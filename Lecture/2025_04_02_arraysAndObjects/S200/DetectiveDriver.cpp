/**
 * DetectiveDriver.cpp
 * 
 * BUILD:
 * g++ -Wall -Werror -Wpedantic -Wsign-compare -std=c++17 Detective.cpp DetectiveDriver.cpp
 */
// #include "Decetive.cpp"  // NO! bad pactice, never include `.cpp`, only `.h`
#include "Detective.h" 
#include<iostream>
#include<cassert>
using namespace std;

int main()
{
    cout << "Hello, World!" << endl;
    // develop an array of Detective objects

    // Sherlock Holmes
    Detective sherlock = Detective( "Sherlock Holmes", 2300 );
    // // cout << sherlock << endl;
    // sherlock.show();

    // Cordelia Cupp
    Detective cordelia = Detective( "Cordelia Cupp", 300 );
    // assert( cordelia.getName() == "Cordelia Cupp!!!!!!" );  // absurd test
    assert( cordelia.getName() == "Cordelia Cupp" );  // a test to pass silently

    // Jake Peralta
    Detective jake = Detective( "Jake Peralta", 14 );

    Detective x[5] = { sherlock, cordelia, jake };

    for ( int i = 0 ; i < 3 ; i++ )
    {
        x[i].show();
    }
    return 0;
}
