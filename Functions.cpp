#include "Functions.h"
#include<iostream>
#include<limits>
#include<algorithm>
#include<string>

void display_menu() {
    std::cout << "\nF - Play First Song" << std::endl;
    std::cout << "N - Play Next song" << std::endl;
    std::cout << "P - Play Previous song" << std::endl;
    std::cout << "A - Add and play a new Song at current location" << std::endl;
    std::cout << "L - List the current playlist" << std::endl;
    std::cout << "E - Play Last song" << std::endl;
    std::cout << "===============================================" << std::endl;
    std::cout << "Enter a selection (Q to quit): ";
}

void play_current_song(const Song &song) {
    std :: cout << song << std :: endl;
}

void display_playlist(const std::list<Song> &playlist, const Song &current_song) {
    for (const auto &i : playlist){
        std :: cout << i << std :: endl;
    }
    std :: cout << "Current song : " << current_song << std :: endl;
}

char to_upper(char c){
    return std :: toupper(c);
}

void get_details(std :: string &artist, std :: string &song, int &rat)
{
    std :: cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    std :: cout << "Enter the Artist : "; std :: getline(std :: cin, artist);
    std :: cout << "Enter the song : "; std :: getline(std :: cin, song);
    std :: cout << "Whats your rating ? : "; std :: cin >> rat;
}
