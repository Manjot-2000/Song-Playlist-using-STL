#ifndef _SONG_H_
#define _SONG_H_

#include<iostream>
#include<string>
class Song
{
    friend std::ostream &operator<<(std::ostream &os, const Song &s);
    std::string name;
    std::string artist;
    int rating;
public:
    Song() = default;
    Song(std::string name, std::string artist, int rating); 
    bool operator<(const Song &rhs) const;
    bool operator==(const Song &rhs) const;
};


#endif             //_SONG_H_ 
