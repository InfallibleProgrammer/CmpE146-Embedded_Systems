#include "mp3_decoder.h"

extern MP3_DECODER mp3;

MP3_DECODER::MP3_DECODER()
{
    RST = NULL;
    DREQ = NULL;
    XCS = NULL;
    XDCS = NULL;
    status.byte = 0;
    sending_cmd = NULL;
    state = STOP;
}

bool MP3_DECODER::init(GPIO * rst, GPIO * dreq, GPIO * cs, GPIO * xdcs)
{
    printf("MP3 INIT_START :: ");

    sending_cmd = xSemaphoreCreateBinary();
    if(sending_cmd == NULL)
    {
        printf("SEMPHR_DOWN :: ");
        return false;
    }
    printf("SEMPHR_UP :: ");

    RST = rst;
    DREQ = dreq;
    XCS = cs;
    XDCS = xdcs;

    if(RST == NULL || DREQ == NULL || XCS == NULL || XDCS == NULL)
    {
        return false;
    }

    RST->setAsOutput();
    XCS->setAsOutput();
    XDCS->setAsOutput();
    DREQ->setAsInput();

    RST->setLow();
    XCS->setHigh();
    XDCS->setHigh();

    printf("PIN_SET :: ");

    ssp0_init(8);
    //    ssp0_set_max_clock(10);
    printf("SPI_SET :: ");

    RST->setHigh();

    status.init_done = true;

    printf("BOOT");
    if(xSemaphoreTake(sending_cmd, NULL))
    {
        printf("ED :: ");
    }
    else
    {
        printf(" INCOMPLETE :: ");
    }

    sendSCI(SCI_WRITE, SCI_MODE, ((1<<5)| 0x0810));
    delay_ms(5);
    sendSCI(SCI_WRITE, SCI_CLKF, 0x6000);
    delay_ms(5);
    sendSCI(SCI_WRITE, SCI_AUDATA, 0xAC45);
    delay_ms(5);

    return status.init_done;

}

uint16_t MP3_DECODER::sendSCI(uint8_t opcode, uint8_t addr, uint16_t info)
{
    uint8_t data[2];
    if(RST->read() == false)
    {
        RST->setHigh();
    }

    if((status.init_done == false) || (status.booted == false))
    {
        printf("WARNING: MUST INIT AND BOOT FIRST!\n");
        return 0;
    }
    printf("SEND");

    XCS->setLow();
    ssp0_exchange_byte(opcode);
    ssp0_exchange_byte(addr);
    data[0] = ssp0_exchange_byte(info >> 8);
    data[1] = ssp0_exchange_byte(info & 0xFF);
    XCS->setHigh();

    printf(" :: ");

    delay_ms(1);
    xSemaphoreTake(sending_cmd, portMAX_DELAY);

    return ((data[0] << 8) | data[1]);
}

bool MP3_DECODER::sendSDI(uint8_t info[], unsigned int size)
{
    if(status.init_done == false)
    {
        printf("WARNING: MP3 NOT INITIALIZED.\n");
        return false;
    }

    XDCS->setLow();
    for(int i = 0; i < size; i++)
    {
        if((i%32) == 0)
        {
            if(!xSemaphoreTake(sending_cmd, NULL))
            {
                delay_us(500);
            }
        }
        ssp0_exchange_byte(info[i]);

    }
    XDCS->setHigh();

    return true;
}

void d_req_int_handler()
{
    mp3.status.booted = 1;
    xSemaphoreGiveFromISR(mp3.sending_cmd, NULL);
}

void MP3_DECODER::setVolume(uint8_t left, uint8_t right)
{
    sendSCI(SCI_WRITE, SCI_VOLUME, ((left << 8) | right));
}

// void MP3_DECODER::setTreble(uint8_t percentage)
// {
//     sendSCI(SCI_WRITE, SCI_TREBLE, percentage);
// }

// void MP3_DECODER::setBass(uint8_t value)
// {
//     sendSCI(SCI_WRITE, SCI_BASS, value);
// }

void MP3_DECODER::sineTest(uint8_t frequency)
{
    sineTestStart[3] = frequency;
    sendSCI(SCI_WRITE, SCI_MODE, 0x0824);
    delay_ms(5);

    xSemaphoreTake(sending_cmd, portMAX_DELAY);

    sendSDI(sineTestStart, sizeof(sineTestStart));

    delay_ms(5000); //Run Sine Test for 5 secods

    sendSDI(sineTestEnd, sizeof(sineTestEnd));
    return;
}
