#include "song_database.h"

SONG_NODE::SONG_NODE()
{
	sprintf(FILE_NAME,"\0");
	NEXT = NULL;
	PREV = NULL;
}

SONG_HEADER SONG_NODE::get_song_info(void)
{
	return SONG_INFO;
}

char* SONG_NODE::get_song_identification(void)
{
	return SONG_INFO.identification;
}

char* SONG_NODE::get_song_title(void)
{
	if((SONG_INFO_EXTRA.header == "TAG+") && (SONG_INFO_EXTRA.title[0] != 0))
	{
	    return SONG_INFO_EXTRA.title;
	}
	else if(SONG_INFO.title[0] != 0)
	{
	    return SONG_INFO.title;
	}
    return FILE_NAME;
}

char* SONG_NODE::get_song_artists(void)
{
	return SONG_INFO.artists;
}

char* SONG_NODE::get_song_album(void)
{
	return SONG_INFO.album;
}

char* SONG_NODE::get_song_year(void)
{
	return SONG_INFO.year;
}

char* SONG_NODE::get_song_comment(void)
{
	return SONG_INFO.comment;
}

char SONG_NODE::get_song_genre(void)
{
	return SONG_INFO.genre;
} 

SONG_NODE* SONG_NODE::get_next(void)
{
    return NEXT;
}

SONG_NODE* SONG_NODE::get_prev(void)
{
    return PREV;
}

bool SONG_NODE::import_song_info(void)
{
    FRESULT op_result;
    FIL file_object;
    unsigned int amount_read;
    char file_path[60];

    snprintf(file_path, sizeof(file_path),"1:%s",FILE_NAME);
    printf("OPEN :: ");
    op_result = f_open(&file_object, file_path, FA_READ);
    if(print_fresult_msg(op_result))
    {
        printf("SEEK :: ");
        op_result = f_lseek(&file_object, (f_size(&file_object) - 128 - 227));
        if(print_fresult_msg(op_result))
        {
            printf("READ :: ");
            op_result = f_read(&file_object, &SONG_INFO_EXTRA, sizeof(SONG_INFO_EXTRA) , &amount_read);
            op_result = f_read(&file_object, &SONG_INFO, sizeof(SONG_INFO) , &amount_read);
            if(print_fresult_msg(op_result))
            {
                return true;
            }
        }
        f_close(&file_object);
    }
    return false;
}

bool SONG_NODE::import_song_info(char file_name[])
{
    snprintf(FILE_NAME, sizeof(FILE_NAME), "%s", file_name);
    return import_song_info();
}

char* SONG_NODE::get_file_name(void)
{
    return FILE_NAME;
}

void SONG_NODE::set_file_name(char name[])
{
    strcpy(FILE_NAME, name);
}

void SONG_NODE::set_next(SONG_NODE* next)
{
    NEXT = next;
}

void SONG_NODE::set_prev(SONG_NODE* prev)
{
    PREV = prev;
}

SONG_DATABASE::SONG_DATABASE()
{
	HEAD = NULL;
	TAIL = NULL;
	number_of_songs_found = 0;
}

bool SONG_DATABASE::import_songs(char file_path[])
{
	SONG_NODE * current = new SONG_NODE;
    DIR directory;
    FRESULT file_result;
    FILINFO file_info;
    int count = 0;
    char result_buffer[50];

    file_result = f_getlabel("1:", result_buffer, 0);
    if(print_fresult_msg(file_result))
    {
        printf("LABEL:: %s\n", result_buffer);
    }

    file_result = f_opendir(&directory, file_path);
    if(print_fresult_msg(file_result))
    {
    	printf("SONG LIST: \n");
        for(;;)
        {
            file_result = f_readdir(&directory, &file_info);
            if((file_result != FR_OK) || (file_info.fname[0] == 0)) break;
            if(file_info.fattrib & AM_DIR)
            {
                //IT'S A DIRECTORY, MAY IMPLEMENT FOR PLAYLISTS LATER.
            }
            else if((strstr(file_info.fname,".MP3") != NULL) || (strstr(file_info.fname,".mp3") != NULL))
            {
                if(HEAD == NULL)
                {
                	HEAD = current;
                	TAIL = current;
                }
                else
                {
                	current = new SONG_NODE;
                	current->set_prev(TAIL);
                	TAIL->set_next(current);
                	TAIL = current;
                }

                current->import_song_info(file_info.fname);
                printf("%d: ", ++count);
                printf("%s \n", current->get_song_title());
            }
            else if(strstr(file_info.fname,"?") != NULL)
            {

                printf("?: %s\n", file_info.fname);
            }
            else
            {
                printf("X: %s\n", file_info.fname);
            }
        }
        f_closedir(&directory);
        number_of_songs_found = count;
        return true;
    }

    return false;
}

bool SONG_DATABASE::print_songs()
{
	SONG_NODE * current = HEAD;
	if(HEAD == NULL)
	{
		return false;
	}
	printf("Song List: \n");
	while(current != NULL)
	{
		printf("%s\n", current->get_file_name());
		current = current->get_next();
	}
	printf("List End.\n");
	return true;
}

SONG_NODE* SONG_DATABASE::get_head()
{
    return HEAD;
}

SONG_NODE* SONG_DATABASE::get_tail()
{
    return TAIL;
}

void SONG_DATABASE::set_head(SONG_NODE* head)
{
    HEAD = head;
    return;
}

void SONG_DATABASE::set_tail(SONG_NODE* tail)
{
    TAIL = tail;
    return;
}

bool print_fresult_msg(FRESULT op_result)
{
    switch(op_result)
    {
        case FR_OK:
            return true;
            break;
        case FR_DISK_ERR:
            printf("File Error: DISK_ERR.\n");
            break;
        case FR_INT_ERR:
            printf("File Error: INT_ERR.\n");
            break;
        case FR_NOT_READY:
            printf("File Error: NOT_READY.\n");
            break;
        case FR_NO_FILE:
            printf("FILE ERROR: NO_FILE.\n");
            break;
        case FR_NO_PATH:
            printf("File Error: NO_PATH.\n");
            break;
        case FR_INVALID_NAME:
            printf("File Error: INVALID_NAME.\n");
            break;
        case FR_DENIED:
            printf("File Error: Permission DENIED.\n");
            break;
        case FR_INVALID_OBJECT:
            printf("File Error: INVALID_OBJECT.\n");
            break;
        case FR_TIMEOUT:
            printf("File Error: TIMEOUT.\n");
            break;
        case FR_INVALID_DRIVE:
            printf("File Error: INVALID_DRIVE.\n");
            break;
        case FR_NOT_ENABLED:
            printf("File Error: NOT_ENABLED.\n");
            break;
        case FR_NO_FILESYSTEM:
            printf("File Error: NO_FILESYSTEM.\n");
            break;
        case FR_NOT_ENOUGH_CORE:
            printf("File Error: NOT_ENOUGH_CORE.\n");
            break;
        case FR_TOO_MANY_OPEN_FILES:
            printf("File Error: TOO_MANY_OPEN_FILES.\n");
            break;
        default:
            printf("File Error: Invalid FRESULT return.\n");
            break;
    }
    return false;
}
