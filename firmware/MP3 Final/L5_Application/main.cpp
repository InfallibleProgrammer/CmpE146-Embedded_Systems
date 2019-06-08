#include <stdint.h>
#include <stdio.h>
#include <cstdio>
#include "FreeRTOS.h"
#include "tasks.hpp"
#include "task.h"
#include "lpc17xx.h"
#include "semphr.h"
#include <string.h>
#include <cstring>
#include "queue.h"
#include "io.hpp"
#include "uart3.hpp"
#include "song_database.h"
#include "LCDComms.h"
#include "mp3_decoder.h"
#include "labgpiointerrupt.h"

//Gobal Variable
SONG_DATABASE song_database;      //Listing of all songs found on SD card
SONG_NODE * cursor_song = NULL;
SONG_NODE * current_playing_song = NULL;
char current_directory[30];
QueueHandle_t song_selected;
QueueHandle_t audio_data;
Uart3 &lcd = Uart3::getInstance();
LCDCOMMS lcd_display;

MP3_DECODER mp3;
GPIO rst(P1_29);
GPIO xdcs(P1_28);
GPIO xcs(P1_23);
GPIO dreq(P0_30);

//GPIO enter(P0_0);
//GPIO play(P0_1);
//GPIO next(P2_6);
//GPIO prev(P2_7);

void vlcd_display(void * pvParameters);
void update_display(void);
void vPlaySong(void * pvParameters);
void audioDecoderTask(void * pvParameters);
void c_eint3_handler();
void vbuttonTask(void * pvParameters);
void selectButton();
void playButton();
void nextButton();
void prevButton();

LabGPIOInterrupts interrupts;

int main(void)
{
    const uint32_t STACK_SIZE = 2048;
    const uint32_t MAX_SONGS = 10;
    song_selected = xQueueCreate(MAX_SONGS, sizeof(SONG_NODE *));
    audio_data = xQueueCreate(3, sizeof(char[512]));
    if (song_selected == NULL || audio_data == NULL)
    {
        printf("Error: Queues were not created.\n");
    }

    snprintf(current_directory, sizeof(current_directory), "1:");

    if (song_database.import_songs(current_directory))
    {
        if (song_database.get_head() != NULL)
        {
            cursor_song = song_database.get_head();
        }
        else
        {
            printf("No songs were successfully imported.\n");
            cursor_song = NULL;
        }
    }

    interrupts.init();
    interrupts.attachInterruptHandler(0, 30, d_req_int_handler, rising_edge);
    interrupts.attachInterruptHandler(0, 0, selectButton, rising_edge);
    interrupts.attachInterruptHandler(0, 1, playButton, rising_edge);
    interrupts.attachInterruptHandler(2, 6, nextButton, rising_edge);
    interrupts.attachInterruptHandler(2, 7, prevButton, rising_edge);

    isr_register(EINT3_IRQn, c_eint3_handler);

    if (mp3.init(&rst, &dreq, &xcs, &xdcs))
    {
        printf("RUNNING!\n");
    }

    xTaskCreate(vPlaySong, "PlaySong",  STACK_SIZE, NULL, PRIORITY_MEDIUM, NULL);
    xTaskCreate(vlcd_display, "LCD",    STACK_SIZE, NULL, PRIORITY_MEDIUM, NULL);
    xTaskCreate(audioDecoderTask, "MP3", STACK_SIZE, NULL, PRIORITY_HIGH, NULL);
    xTaskCreate(vbuttonTask, "BUTTONS", STACK_SIZE, NULL, PRIORITY_MEDIUM, NULL); //TO BE REMOVED. USE ISRs in FINAL
    scheduler_add_task(new terminalTask(PRIORITY_HIGH));
    printf("Initialization Done.\n");

    scheduler_start();

    return -1;
}


void vbuttonTask(void * pvParameters)
{
    bool button_pressed[5] = {false};
    while (1)
    {
        for (int i = 1; i < 5; i++)
        {
            if (SW.getSwitch(i) && (button_pressed[i] == false))
            {
                button_pressed[i] = true;
            }
            if (button_pressed[i] && (SW.getSwitch(i) == false))
            {
                switch (i)
                {
                case 1: //PREV
                    if ((cursor_song != NULL) && (cursor_song->get_prev() != NULL))
                    {
                        cursor_song = cursor_song->get_prev();
                    }
                    update_display();
                    break;
                case 2: //SELECT
                    if (cursor_song != NULL)
                    {
                        xQueueSend(song_selected, &cursor_song, NULL);
                        mp3.state = MP3_DECODER::PLAY;
                    }
                    break;
                case 3: //NEXT
                    if ((cursor_song != NULL) && (cursor_song->get_next() != NULL))
                    {
                        cursor_song = cursor_song->get_next();
                    }
                    update_display();
                    break;
                case 4: //CURRENT: PRINT SONG !!!TODO: PLAY/PAUSE
//                        song_database.print_songs();
                    if (mp3.state == MP3_DECODER::PLAY)
                    {
                        mp3.state = MP3_DECODER::PAUSE;
                    }
                    else
                    {
                        mp3.state = MP3_DECODER::PLAY;
                    }
                    break;
                default:
                    break;
                }
                button_pressed[i] = false;
            }
        }
        vTaskDelay(250);
    }
}

void vPlaySong(void * pvParameters)
{
    char data[512] = {0};
    char song_file[40];
//    char SD_SELECT[3] = "0:";
    FIL file_object;
    FRESULT file_result;
    size_t amount_read, total_read;
    SONG_NODE next_song;

    while (1)
    {
        if (xQueueReceive(song_selected, &current_playing_song, portMAX_DELAY))
        {
            printf("Requested to play: %s.\n", current_playing_song->get_song_title());
            snprintf(song_file, sizeof(song_file), "1:/%s", current_playing_song->get_file_name());
            file_result = f_open(&file_object, song_file, FA_READ);
            printf("OPEN :: ");
            if (print_fresult_msg(file_result))
            {
                printf("READ :: ");
                while (total_read <= f_size(&file_object))
                {
                    if (xQueuePeek(song_selected, &next_song, NULL))
                    {
                        if (next_song.get_file_name() != current_playing_song->get_file_name()) break;
                    }
                    f_read(&file_object, data, sizeof(data), &amount_read);
                    if (print_fresult_msg(file_result))
                    {
                        xQueueSend(audio_data, data, portMAX_DELAY);
                        total_read += amount_read;
                    }
                }
                amount_read = 0;
                total_read = 0;
                file_result = f_close(&file_object);
                print_fresult_msg(file_result);
                printf("FINISHED: %s.\n", current_playing_song->get_song_title());
                current_playing_song = NULL;
            }
            else
            {
                print_fresult_msg(file_result);
                current_playing_song = NULL;
            }
        }
    }
}

void vlcd_display(void * pvParameters)
{
    lcd.init(38400);                //Init UART Driver
    vTaskDelay(100);
    lcd.putChar(0xF0);              //Init Baudrate on LCD Display
    vTaskDelay(1000);
    while (1)
    {
        update_display();
        vTaskDelay(2000);
    }
}

void update_display(void)
{
    char line[4][21];
    lcd.printf("$CLR_SCR\n");
    if (current_playing_song != NULL)
    {
        snprintf(line[0], sizeof(line[0]), "Playing:%s", current_playing_song->get_song_title());
    }
    else
    {
        snprintf(line[0], sizeof(line[0]), "Nothing is playing.");
    }

    if (cursor_song != NULL)
    {
        if ((cursor_song->get_prev() == NULL) && (cursor_song->get_next() == NULL))
        {
            snprintf(line[1], sizeof(line[1]), "                          ");
            snprintf(line[2], sizeof(line[2]), "%s", cursor_song->get_song_title());
            snprintf(line[3], sizeof(line[3]), "                          ");
        }
        else if (cursor_song->get_prev() == NULL)
        {
            snprintf(line[1], sizeof(line[1]), "->%s", cursor_song->get_song_title());
            if (cursor_song->get_next() != NULL)
            {
                snprintf(line[2], sizeof(line[2]), "  %s", cursor_song->get_next()->get_song_title());
                if (cursor_song->get_next()->get_next() != NULL)
                {
                    snprintf(line[3], sizeof(line[3]), "  %s", cursor_song->get_next()->get_next()->get_song_title());
                }
            }
        }
        else if (cursor_song->get_next() == NULL)
        {
            if (cursor_song->get_prev() != NULL)
            {
                if (cursor_song->get_prev()->get_prev() != NULL)
                {
                    snprintf(line[1], sizeof(line[1]), "  %s", cursor_song->get_prev()->get_prev()->get_song_title());
                }
                snprintf(line[2], sizeof(line[2]), "  %s", cursor_song->get_prev()->get_song_title());
            }
            snprintf(line[3], sizeof(line[3]), "->%s", cursor_song->get_song_title());
        }
        else
        {
            snprintf(line[1], sizeof(line[1]), "  %s", cursor_song->get_prev()->get_song_title());
            snprintf(line[2], sizeof(line[2]), "->%s", cursor_song->get_song_title());
            snprintf(line[3], sizeof(line[3]), "  %s", cursor_song->get_next()->get_song_title());
        }
    }
    else
    {
        snprintf(line[1], sizeof(line[1]), "                          ");
        snprintf(line[2], sizeof(line[2]), "No songs were stored.");
        snprintf(line[3], sizeof(line[3]), "                          ");
    }

    lcd_display.write(0, 0, line[0]);
    lcd_display.write(0, 1, line[1]);
    lcd_display.write(0, 2, line[2]);
    lcd_display.write(0, 3, line[3]);

//
//    printf("\n---------- OUTPUT ------------\n");
//    printf("%s\n", line[0]);
//    printf("%s\n", line[1]);
//    printf("%s\n", line[2]);
//    printf("%s\n", line[3]);
//    printf("------------------------------\n");
}

void audioDecoderTask(void * pvParameters)
{
    uint8_t data[512];
    uint8_t pause = 0;
    vTaskDelay(5);
    mp3.setVolume(70, 70);
//    vTaskDelay(5);
//    mp3.sendSCI(MP3_DECODER::SCI_WRITE, MP3_DECODER::SCI_AUDATA, 0xAC45);
//    vTaskDelay(100);
//    mp3.sendSCI(MP3_DECODER::SCI_WRITE, MP3_DECODER::SCI_MODE, ((1 << 5) | 0x0810));
    while (1)
    {
        if (mp3.state == MP3_DECODER::PLAY)
        {
//            printf("CHUNK :: ");
            xQueueReceive(audio_data, data, portMAX_DELAY);
            mp3.sendSDI(data, sizeof(data));
        }
//        mp3.sineTest(0x03);
        vTaskDelay(10);
    }
}

void c_eint3_handler()
{
    interrupts.handle_interrupt();
}

void selectButton()
{
    if (cursor_song != NULL)
    {
        xQueueSendFromISR(song_selected, &cursor_song, NULL);
        mp3.state = MP3_DECODER::PLAY;
    }
}

void playButton()
{
    if (mp3.state == MP3_DECODER::PLAY)
    {
        mp3.state = MP3_DECODER::PAUSE;
    }
    else
    {
        mp3.state = MP3_DECODER::PLAY;
    }
}

void nextButton()
{
    if ((cursor_song != NULL) && (cursor_song->get_next() != NULL))
    {
        cursor_song = cursor_song->get_next();
    }
    update_display();
}

void prevButton()
{
    if ((cursor_song != NULL) && (cursor_song->get_prev() != NULL))
    {
        cursor_song = cursor_song->get_prev();
    }
    update_display();
}
