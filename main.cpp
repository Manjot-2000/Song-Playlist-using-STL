#include <iostream>
#include <list>
#include <cctype>
#include "Functions.h"
#include "Song.h"

int main() {

    std::list<Song> playlist{
            {"God's Plan",        "Drake",                     5},
            {"Never Be The Same", "Camila Cabello",            5},
            {"Pray For Me",       "The Weekend and K. Lamar",  4},
            {"The Middle",        "Zedd, Maren Morris & Grey", 5},
            {"Wait",              "Maroone 5",                 4},
            {"Whatever It Takes", "Imagine Dragons",           3}          
    };
    
    std::list<Song>::iterator current_song = playlist.begin();
    
    char choice;
    do
    {
        display_menu();
        std :: cin >> choice;
        choice = to_upper(choice);

        switch(choice)
        {
            case 'F':
                current_song = playlist.begin();
                play_current_song(*current_song);
                break;
            case 'N':
                if(*current_song == playlist.back())
                    current_song = playlist.begin();
                else
                    current_song++;    
                play_current_song(*current_song);
                break;
            case 'P':
                 if(*current_song == playlist.front()){
                    current_song = playlist.end();
                    current_song--;
                 }
                play_current_song(*current_song);
                break;
            case 'A':
                {
                    std :: string set_name, set_song;
                    int set_rating;
                    get_details(set_name, set_song, set_rating);
                    playlist.emplace(current_song, Song{set_name, set_song, set_rating});
                    current_song--;
                    play_current_song(*current_song);
                }
                break; 
            case 'L':
                display_playlist(playlist, *current_song);
                break;
            case 'E':
                current_song = playlist.end();
                current_song--;
                play_current_song(*current_song);
            case 'Q':
                std :: cout << "Thanks for listening!" << std :: endl;      
                break; 
            default:
                std :: cout << "\nInvalid selection, please try agian\n\n";
                break;                      
        }

    } while (choice != 'Q');
    return 0;
}