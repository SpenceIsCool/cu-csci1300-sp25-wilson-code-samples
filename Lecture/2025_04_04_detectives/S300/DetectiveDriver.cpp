// DetectiveDriver.cpp
#include "Detective.h"
#include<iostream>
using namespace std;


void incrementAllSolved( Detective arr[], int len );


int main()
{
    // cout << "Hello, detective!" << endl;
    // // just getting prepped
    // Detective tmp = Detective();
    // tmp.print();
    
    // make detectives: Sherlock Holmes, Cordelia Cupp, and Jake Peralta
    Detective sh = Detective( "Sherlock Holmes", 1300 );
    Detective cc = Detective( "Cordelia Cupp", 340 );
    Detective jp = Detective();
    jp.setName( "Jake Peralta" );
    jp.setSolvedCases( 14 );

    // put them in an array
    Detective x[10] = { sh, cc, jp };

    // do cool stuff with the array
    for ( int i = 0 ; i < 3 ; i++ )
    {
        x[i].print();
    }

    incrementAllSolved( x, 3 );
    
    for ( int i = 0 ; i < 3 ; i++ )
    {
        x[i].print();
    }

    return 0;
}




void incrementAllSolved( Detective arr[], int len )
{
    for ( int i = 0 ; i < len ; i++ )
    {
        unsigned short solvedSoFar = arr[i].getSolvedCases();
        unsigned short newValue = solvedSoFar + 1;
        arr[i].setSolvedCases( newValue );
    }

}



