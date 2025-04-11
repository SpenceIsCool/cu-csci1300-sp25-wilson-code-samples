// Song.h


#ifndef SONG_H
#define SONG_H


#include<string>
using namespace std;


class Song
{
public:
    Song( string a, string t );
    void showSong( ) const;
    void setArtist( string a );
private:
    string artist;
    string title;
};


#endif
