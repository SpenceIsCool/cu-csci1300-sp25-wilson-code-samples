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

    // ifstream myFile;
    // myFile.open( fileName );
    ifstream myFile( fileName );

    if ( ! myFile.is_open() )
    {
        cout << "NOPE!" << endl;
        return EXIT_FAILURE;
    }

    // string myLine;
    // while ( getline( myFile, myLine ) )
    // {
    //     cout << myLine << endl;
    // }

    // string myLine;
    // vector< string > artists;
    // while ( getline( myFile, myLine ) )
    // {
    //     // get the artist from myLine
    //     // ASSUME: myLine is of the form:
    //     //         artist~title
    //     // getline( stream, string, delimeter )
    //     string artist;
    //     istringstream ss( myLine );
    //     getline( ss, artist, '~' );
    //     // cout << artist << endl;

    //     // put the artist in the vector
    //     // // HERE: insert at front
    //     // //       wayyyyy too much code
    //     // artists.insert( artists.begin() + 0, artist );
    //     artists.push_back( artist );

    // }

    // // print the vector
    // // unsigned int required, build with `-Wsign-compare`
    // for ( unsigned int i = 0 ; i < artists.size() ; i++ )
    // {
    //     cout << artists.at(i) << endl;
    // }


    string myLine;
    vector< Song > songs;
    while ( getline( myFile, myLine ) )
    {
        // ASSUME: myLine: artist~title
        // want to see how to ignore COMMENT? see the parent directory on github linked on the powerpoint slides
        string artist, title;
        istringstream ss( myLine );
        getline( ss, artist, '~' );
        getline( ss, title );

        Song song { artist, title };
        songs.push_back( song );

    }

    // print the vector
    // unsigned int required, build with `-Wsign-compare`
    for ( unsigned int i = 0 ; i < songs.size() ; i++ )
    {
        cout << songs.at(i).artist << " has a song named " << songs.at(i).title << endl;
    }

    myFile.close();

    return 0;
}


