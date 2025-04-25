// exam.cpp
#include<sstream>
#include<fstream>
#include<iostream>
#include<cassert>
#include<vector>
using namespace std;

void confirmTest();

string foo( string x );
void testFoo( string x, string expected );
void testAllFoo();

bool isOdd( int y );
struct MyStruct {
    int special;
    bool idc;
    string whatever;
};
size_t countOdd( MyStruct arr[], size_t len );
void testAllCount();

void prependDont( string x[][2], unsigned int len );
void printMat( string x[][2], unsigned int len );
void testAllMat();


struct Hand {
    int value;
    string details; 
};
vector<Hand> rmEvenIndices1( vector<Hand> table );
vector<Hand> rmEvenIndices2( vector<Hand> table );
vector<Hand> rmEvenIndices3( vector<Hand> table );
void testAllRmEvenIndices( );

void stripComments( string ifn, string ofn );
void testStream();

int main()
{
    testAllFoo();
    testAllCount();
    testAllMat();
    testAllRmEvenIndices();
    testStream();
    cout << "$$$$$ ALL TESTS PASSED" << endl;
    return 0;
}




void confirmTest()
{
    string x;
    cout << "did this test work [1 for yes/0 for no]?" << endl;
    getline( cin, x );
    if ( x == "yes" || x == "1" )
    {
        cout << "thanks" << endl;
        return;
    }
    
    if ( x == "no" || x == "0" )
    {
        string y =  "sorry to hear that";
        string z = "aborting testing";
        cout << y << ' ' << z << endl;
        assert( y == z  );
    }

    cout << "let's try that again..." << endl;
    confirmTest();
    return;
}




string foo( string x ) 
{
    string result = "";
    if ( x != "" ) {
        istringstream y( x );
        string z, remaining;
        getline( y, z, ':' );
        getline( y, remaining );
        if ( z.length() % 2 == 0 ) {
            result = z + ">" + foo( remaining );
        } else {
            result = foo( remaining );
        } 
    }
    return result;
}
void testFoo( string x, string expected )
{
    cout << "foo( " << x << " )" << endl
         << "    EXPECTED: " << expected << endl;
    string found = foo( x );
    cout << "    FOUND: " << found << endl;
    assert( expected == found );
}
void testAllFoo()
{
    testFoo( "", "");
    testFoo( "even", "even>");
    testFoo( "odd", "");
    testFoo( ":1:23", ">23>");
    testFoo( "hi:there:sup:dude", "hi>dude>");
}









bool isOdd( int y ) {
    if ( y == 0 ) return false;
    else if ( y == 1 || y == -1 ) return true;
    if ( y > 0 ) return isOdd( y - 2 );
    return isOdd( y + 2 );
}
size_t countOdd( MyStruct arr[], size_t len )
{
    size_t res = 0;
    for ( size_t i = 0 ; i < len ; i++ )
    {
        if ( isOdd( arr[i].special ) )
        {
            res++;
        }
    }
    return res;
}
void testAllCount()
{
    assert( isOdd( 3 ) == true );
    assert( isOdd( 2 ) == false );
    assert( isOdd( -10 ) == false );
    assert( isOdd( -11 ) == true );
    MyStruct x[4] = { { 1, false, "hi" }, 
                      { 0, false, "idk" }, 
                      { 2, true, "hey" }, 
                      { -3, false, "sup" } };
    assert( countOdd( x, 0 ) == 0 );
    assert( countOdd( x, 1 ) == 1 );
    assert( countOdd( x, 2 ) == 1 );
    assert( countOdd( x, 3 ) == 1 );
    assert( countOdd( x, 4 ) == 2 );
}






void prependDont( string x[][2], unsigned int len ) {
    for ( unsigned int i = 0 ; i < len ; i++ ) {
        x[i][1] = x[i][0];
        x[i][0] = "Don't";
    }
}
void printMat( string x[][2], unsigned int len ) {
    for ( unsigned int row = 0 ; row < len ; row++ ) {
        for ( unsigned int col = 0 ; col < 2 ; col++ ) {
            if ( col != 0 ) { 
                cout << " "; 
            }
            cout << x[row][col];
        }
        cout << endl;
}   }
void testAllMat()
{
    string mat[4][2] =  {
        { "stop", "overthinking" },
        { "think" },
        { "procrastinate" },
        { "give up" }
    };
    prependDont( mat, 1 );
    printMat( mat, 2 );
    cout << "Does the above look correct?" << endl;
    confirmTest();
}





/**
 * rmOddIndices
 * 
 * INPUT: A, B, C, D, E, F
 * OUTPUT: B, D, F
 * 
 * there are SOOOOO many valid ways to do this, I'll write up three of them
 * 
 * @param table: vector of objects
 * @returns: table with every odd index removed
 */
vector<Hand> rmEvenIndices1( vector<Hand> table )
{
    // using .at and .push_back
    vector<Hand> result;
    // note how this skips over the odds
    for ( unsigned int i = 1 ; i < table.size( ) ; i += 2 )
    {
        result.push_back( table.at( i ) );
    }
    return result;
}
vector<Hand> rmEvenIndices2( vector<Hand> table )
{
    // just `.at`
    vector<Hand> result( table.size() / 2 );
    // note how this skips over the odds
    for ( unsigned int i = 1 ; i < table.size( ) ; i += 2 )
    {
        result.at( i / 2 ) =  table.at( i );
    }
    return result;
}
vector<Hand> rmEvenIndices3( vector<Hand> table )
{
    // using `.erase`
    // be careful about indexing, best to erase from the back

    // precondition: length 0 and 1 tables return length 0 vectors
    if ( table.size() < 2 ) return {};

    // carefully find the back deleteable index (2, 4, 6, ...)
    int back_index = table.size() - 1;
    int last_even_index;
    if ( back_index % 2 == 0 )
    {
        last_even_index = back_index;
    }
    else
    {
        last_even_index = back_index - 1;
    }
    // be sure to skip over the odds
    for ( int i = last_even_index ; i > -1 ; i -= 2 )
    {
        // pass by value, so this should be fine
        table.erase( table.begin() + i );
    }

    return table;
}
void testAllRmEvenIndices( )
{
    vector<Hand> table;
    table.push_back( { 11, "double down" } );
    table.push_back( { 17, "troublesome hand" } );
    table.push_back( { 21, "blackjack" } );
    
    vector<Hand> res;

    res = rmEvenIndices1( table ); // index 0 and index 2 removed
    assert( res.size() == 1 );
    assert( res.at( 0 ).details == "troublesome hand" );
    assert( res.at( 0 ).value == 17 );

    table.push_back( { 23, "bust" } );

    res = rmEvenIndices2( table ); // index 0 and index 2 removed
    assert( res.size() == 2 );
    assert( res.at( 1 ).value == 23 );

    res = rmEvenIndices3( table ); // index 0 and index 2 removed
    assert( res.size() == 2 );
    assert( res.at( 1 ).details == "bust" );
}







/**
 *  Write a function, given two file names as strings,
 * read data from the first file, write the data to the second file, 
 * but remove all lines which begin with the phrase `COMMENT :`.
 *  Do not change the first file. Use best practices to open and close files.
 */
void stripComments( string ifn, string ofn )
{
    // intentionally showing both opening patterns, it's not specific to either.
    ifstream ifs( ifn );
    if ( ifs.fail() ) 
    {
        cout << "could not open " << ifn << endl;
        return;
    }

    ofstream ofs;
    ofs.open( ofn );
    if ( ! ofs.is_open( ) )
    {
        cout << "could not open " << ofn << endl;
        // don'f forget to close ifs which was opened successfully
        ifs.close();
        return;
    }

    // read every line of the input file
    string line;
    while ( getline( ifs, line ) )
    {
        // ignore it if it starts with `COMMENT :`
        istringstream iss( line );
        string maybeComment;
        // getline( iss, maybeComment, ':');  // this could work
        iss >> maybeComment;
        iss.ignore();
        if ( iss.get() == ':' && maybeComment == "COMMENT" )
        {
            cout << "-- IGNORE:" << line << endl;
        }
        else
        {
            cout << "++++ ADD:" << line << endl;
            ofs << line << endl;
        }
    }

    // don't forget to close the files
    ifs.close();
    ofs.close();
}
void testStream()
{
    stringstream x;
    x << "hello   my name is" << endl
      << "Gregor" << endl
      << "and more stuff is here";
    string y0, y1, y2;
    x >> y0; // y0 is "hello"
    // CHANGE CODE
    x.ignore(3);
    getline( x, y1, 'g' );  // y1 is "   my name is<NEW_LINE>Gr
    getline( x, y2 );  // y2 is "gor"
    confirmTest();

    cout << "y0:" << y0 << endl
         << "y1:" << y1 << endl
         << "y2:" << y2 << endl;
    assert(y0 == "hello");


    stripComments( "in.txt", "out.txt" );
    cout << "open in.txt and out.txt" << endl
         << "does out.txt not have the lines that begin with 'COMMENT :'?" << endl;
    confirmTest();
    return;
}