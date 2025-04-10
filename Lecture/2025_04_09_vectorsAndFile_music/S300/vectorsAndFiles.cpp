/**
 * vectorsAndFiles.cpp
 * 
 */
// note what is #include<d>
#include<vector>
#include<fstream>
#include<sstream>
#include<iostream>
using namespace std;


struct Song
{
    string artist;
    string title;
};


int main( )
{
    string fileName = "songs.txt";

    // make a file, open it and read it
    // ifstream myFile;
    // myFile.open( fileName );
    ifstream myFile( fileName );

    if ( myFile.is_open() )
    {
        string myLine;
        vector<string> artists;
        vector<Song> songs;
        // read each line of the file
        while ( getline( myFile, myLine ) ) 
        {
            // // print all lines
            // cout << myLine << endl;

            // print all artists?
            // ASSUME: myLine: artist~song title
            // how to cut on the `~`? use getline
            istringstream ss( myLine );
            string artist;
            getline( ss, artist, '~' );
            // cout << artist << endl;

            // put the artist in the vector
            artists.push_back(artist);

            // get the song
            // myLine: artist~title
            // ss: title
            string title;
            getline( ss, title );
            Song song = { artist, title };
            // songs.push_back( song );
            // instead, insert at front:
            // songs.insert( songs.begin() + 0, song );  // + 0 should be optional
            songs.insert( songs.begin(), song );  // + 0 should be optional
        }

        // print the vector
        for ( unsigned int i = 0 ; i < artists.size() ; i++ )
        {
            // cout << artists.at( i ) << endl;
            cout << songs.at(i).title << " is sang by " << songs.at( i ).artist << endl;
        }
    }

    myFile.close();
    return 0;
}


