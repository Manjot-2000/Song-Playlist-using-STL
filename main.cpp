#include <iostream>
#include <list>
#include <cctype>
#include "Functions.h"
#include "Song.h"

int main() {

    std::list<Song> playlist{
            {"Perfect",                "Ed-Sheeran",                     5},
            {"Lose Yourself",          "Eminem",                         5},
            {"Shake it off",           "Taylor Swift",                   4},
            {"I want it that way",     "Backstreet boys",                5},
            {"Ghosts n stuff",         "DeadMau5",                       4},
            {"Party rock",             "LMFAO",                          3}          
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
                 }
                current_song--;
                play_current_song(*current_song);
                break;
            case 'A':
                {
                    std :: string set_name, set_song;
                    int set_rating;
                    get_details(set_name, set_song, set_rating);
                    if(set_rating > 5){
                            set_rating = 5;
                        }
                        else if(set_rating < 0){
                            set_rating = 0;
                        }
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
