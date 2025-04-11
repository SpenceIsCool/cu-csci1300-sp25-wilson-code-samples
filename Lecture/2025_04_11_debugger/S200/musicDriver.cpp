/**
 * musicDriver.cpp
 * 
 * A student asks: what if we need multiple objects
 * can we edit one object and get it to add to the vector fine for us?
 * 
 * the answer is yes, see below.
 * 
 * note I didn't bother with best practices of class construction:
 * - no default constructor
 * - limited getters and setters
 */


// note what is #include<d>
#include<vector>
#include<fstream>
#include<sstream>
#include<iostream>
#include "Song.h"
using namespace std;




int main( )
{
    // string fileName = "songs.txt";
    // fine, but let's get user input....
    cout << "I can haz filename?" << endl;
    string fileName;
    cin >> fileName;
    

    // make a file, open it and read it
    // ifstream myFile;
    // myFile.open( fileName );
    ifstream myFile( fileName );

    if ( myFile.fail() )
    {
        cout << "NOPE!" << endl;
        return EXIT_FAILURE;
    }

    // read each line of the file
    string myLine;
    vector<Song> songs;
    while ( getline( myFile, myLine ) ) 
    {
        // ASSUME: myLine: artist~song title
        // how to cut on the `~`? use getline
        istringstream ss( myLine );
        string artist;
        getline( ss, artist, '~' );

        // but what if artist starts `COMMENT:`?
        // then skip adding this to the vector
        istringstream ss2( artist );
        string tmp;
        getline( ss2, tmp, ':' );
        if ( tmp == "COMMENT" )
        {
            cout << "a comment was found: " << ss.str( ) << endl;
            continue;
        }

        // get the song
        // myLine: artist~title
        // ss: title
        string title;
        getline( ss, title );

        // make the song
        Song song = Song( artist, title );


        songs.push_back( song );
        
        // Assume that Weird Al makes a cover of every song...
        song.setArtist( "Weird Al" );
        songs.push_back( song ); 
    }

    // print the vector
    for ( unsigned int i = 0 ; i < songs.size() ; i++ )
    {
        cout << i+1 << " ";
        songs.at( i ).showSong( );
    }

    myFile.close();
    return 0;
}


