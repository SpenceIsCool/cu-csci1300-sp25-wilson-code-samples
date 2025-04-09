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


int basicSolution();

bool isValidSong( string s );
Song lineToSong( string s );
void showArtists( vector<Song> mySongs );
int usingHelperFunctions();


int main( )
{
    basicSolution( );
    usingHelperFunctions( );
}


int basicSolution()
{
    cout << endl
         << endl
         << ">>>>>>>>>>>>>>>>> basicSolution"
         << endl;

    vector< Song > mySongs;

    ifstream f( "songs.txt" );
    if ( !f.is_open( ) )
    {
        cout << "Something went wrong opening the file." << endl;
        return EXIT_FAILURE;
    }
    
    // parse each line of the file to a song and put it in the vector
    string line, artist, title;
    while ( getline( f, line ) )
    {
        // assume: artist~title
        // deconstruct
        istringstream sline( line );
        getline( sline, artist, '~');
        getline( sline, title );

        // make the struct: order matters
        Song s{ artist, title };
        
        // put in the vector
        mySongs.push_back( s );
    }


    // use the vector to show the artists found
    for ( unsigned int i = 0 ; i < mySongs.size() ; i++ )
    {
        cout << mySongs.at( i ).artist << endl;
    }

    // don't forget to return the file!
    f.close( );

    return 0;
}


/**
 * isValidSong
 *
 * basicSolution assumes: artist~title
 * but maybe we have blank lines or things missing ~
 *
 * NOTE: a better design would be to use ~~ as the delimeter so that artists and songs
 *       can include ~ in the name. In the interest of time, that isn't shown here,
 *       but it's an interesting exercise
 *
 * NOTE: some langauges like Scala have an Option data type that makes this easier
 *       a tuple< bool, Song > would also be easier to work with
 */
bool isValidSong( string s )
{
    istringstream ss( s );

    // artist name listed?
    string tmp;
    getline( ss, tmp, '~' );
    if ( tmp == "" ) return false;
    
    // title listed?
    // this will also catch if there was never a `~` to begin with 
    getline( ss, tmp );
    if ( tmp == "" ) return false;

    // since the artist and title are non-empty the song is valid
    return true;
}


/**
 * lineToSong
 *
 * assume: artist~title
 * should call isValidSong first from calling context
 */
Song lineToSong( string s )
{
    istringstream ss( s );
    string artist, title;
    getline( ss, artist, '~' );
    getline( ss, title );
    return { artist, title };
}


/**
 * showArtists
 * ignore artists that start with the word COMMENT:
 */
void showArtists( vector<Song> mySongs )
{
    // use the vector to show the artists found
    for ( unsigned int i = 0 ; i < mySongs.size() ; i++ )
    {
        // check for `COMMENT:` prefix
        istringstream ss( mySongs.at( i ).artist );
        string tmp;
        getline( ss, tmp, ':');
        if ( tmp != "COMMENT" )
        {
            cout << mySongs.at( i ).artist << endl;
        }
    }
}

int usingHelperFunctions()
{
    cout << endl
         << endl
         << "$$$$$$$$$$$$$$$$$ usingHelperFunctions"
         << endl;

    ifstream f( "songs.txt" );
    if ( !f.is_open( ) )
    {
        cout << "Something went wrong opening the file." << endl;
        return EXIT_FAILURE;
    }
    
    vector<Song> mySongs;
    string line;
    while ( getline( f, line ) )
        if ( isValidSong( line ) )
            mySongs.push_back( lineToSong( line ) ); // {} not needed as we have don't have compound statements (only one `;`)

    showArtists( mySongs );

    f.close( );
    return 0;
}


