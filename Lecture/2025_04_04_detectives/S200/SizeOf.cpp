/**
 * SizeOf.cpp
 *
 * a place to test sizeof for classes
 * compile with Detective.cpp and Agency
 * g++ -std=c++17 Detective.cpp Agency.cpp SizeOf.cpp
 */
#include "Agency.h"
#include "Detective.h"
#include <iostream>
using namespace std;


int main( )
{
    Detective scooby = Detective( "Scooby Doo", 54321 );
    scooby.print();
    cout << sizeof( scooby ) << endl;

    Detective longName = Detective( "That one detective with a super long name", 54321 );
    longName.print();
    cout << sizeof( longName ) << endl;
    

    Agency a = Agency( "The FBI" );
    a.showAllDetectives();
    cout << sizeof( a ) << endl;

    // a.setStaff( { scooby, longName }, 2 ); // NO, pass by ref array can't be a temporary like this!
    Detective arr[1000] = { scooby, longName };
    a.setStaff( arr, 2 );
    a.showAllDetectives();
    cout << sizeof( a ) << endl;

    cout << "exactly how those values are known is a CSCI 2400 topic, but you can ask on Ed if you want to know more. I personally have never been interested to know. I'll take time and explore if anyone asks." << endl;
    return 0;
}


