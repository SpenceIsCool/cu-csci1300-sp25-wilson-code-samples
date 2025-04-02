// AgencyDriver.cpp
#include "Agency.h"
#include<iostream>
using namespace std;




int main()
{
    Agency theAgency = Agency();
    theAgency.showAllDetectives();

    theAgency.hire( Detective( "Sherlock Holmes", 1300 ) );
    theAgency.hire( Detective( "Cordelia Cupp", 340 ) );
    theAgency.hire( Detective( "Jake Peralta", 14 ) );

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


