// AgencyDriver.cpp
#include "Agency.h"
// // should I also include Detective.h?
// #include "Detective.h"
#include<iostream>
#include<cassert>
using namespace std;




int main()
{
    Agency theAgency = Agency( "The NSA" );
    theAgency.showAllDetectives();

    Detective arr[3] = { Detective( "Sherlock Holmes", 1300 ), Detective( "Cordelia Cupp", 340 ), Detective( "Jake Peralta", 14 ) };
    theAgency.setStaff( arr, 3 );

    // HW8: issues in adding things that don't exist
    // nullptr: is a special empty array that you shall never access
    theAgency.setStaff( nullptr, 0 );


    // theAgency.hire( Detective( "Sherlock Holmes", 1300 ) );
    // theAgency.hire( Detective( "Cordelia Cupp", 340 ) );
    // theAgency.hire( Detective( "Jake Peralta", 14 ) );
    theAgency.showAllDetectives();

    theAgency.solveNewCase( "Sherlock Holmes" );
    theAgency.solveNewCase( 0 );
    assert( theAgency.getDetective( 0 ).getSolvedCases() == 1302 );
    assert( theAgency.getDetective( "Sherlock Holmes" ).getSolvedCases() == 1302 );
    cout << "$$$$ PASSED ASSERTS" << endl << endl;
    theAgency.showAllDetectives();

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


