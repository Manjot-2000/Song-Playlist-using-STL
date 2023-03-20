#ifndef _FUNCTIONS_H_
#define _FUNCTIONS_H_
#include "Song.h"
#include<list>

char to_upper(char c);
void display_menu();
void play_current_song(const Song &song);
void display_playlist(const std::list<Song> &playlist, const Song &current_song);
void get_details(std :: string &artist, std :: string &song, int &rat);

#endif             //_FUNCTIONS_H_ 
