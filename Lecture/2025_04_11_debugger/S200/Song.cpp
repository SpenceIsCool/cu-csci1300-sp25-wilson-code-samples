// Song.cpp
#include "Song.h"
#include<iostream>
using namespace std;

Song::Song( string a, string t ) { 
    artist = a;
    title = t;
}
void Song::showSong( ) const {
    cout << artist << " sings the song " << title << endl;
}
void Song::setArtist( string a ) {
    artist = a;
    return;
}
