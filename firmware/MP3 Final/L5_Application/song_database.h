#ifndef SONG_DATABASE_H_
#define SONG_DATABASE_H_

#include "ff.h"
#include <cstring>
#include <stdio.h>
#include <stdint.h>

bool print_fresult_msg(FRESULT op_result);

struct SONG_HEADER{
    char identification[3] = {0};
    char title[30] = {0};
    char artists[30] = {0};
    char album[30] = {0};
    char year[4] = {0};
    char comment[30] = {0};
    unsigned char genre = 0;
};

struct SONG_HEADER_EXTRA{
    char header[4] = {0};
    char title[60] = {0};
    char artists[60] = {0};
    char album[60] = {0};
    char speed = 0;
    char genre[30] = {0};
    char start_time[6] = {0};
    char end_time[6] = {0};
};

class SONG_NODE
{
public:
    SONG_NODE(void);
    SONG_HEADER get_song_info(void);
    char* get_song_identification(void);
    char* get_song_title(void);
    char* get_song_artists(void);
    char* get_song_album(void);
    char* get_song_year(void);
    char* get_song_comment(void);
    char get_song_genre(void); 
    SONG_NODE* get_next(void);
    SONG_NODE* get_prev(void);
    char* get_file_name(void);
    bool import_song_info(void);
    bool import_song_info(char[]);
    void set_file_name(char[]);
    void set_next(SONG_NODE*);
    void set_prev(SONG_NODE*);
private:
    char FILE_NAME[50];
    SONG_HEADER SONG_INFO;
    SONG_HEADER_EXTRA SONG_INFO_EXTRA;
    SONG_NODE * NEXT;
    SONG_NODE * PREV;
};

class SONG_DATABASE
{
public:
    SONG_DATABASE(void);
    bool import_songs(char[]);
    bool print_songs(void);
    SONG_NODE* get_head(void);
    SONG_NODE* get_tail(void);
    void set_head(SONG_NODE*);
    void set_tail(SONG_NODE*);

private:
    SONG_NODE * HEAD;
    SONG_NODE * TAIL;
    int number_of_songs_found;
};

#endif //SONG_DATABASE_H_
