/**
 * AgencyDRIVER.cpp
 * 
 * BUILD:
 * g++ -Wall -Werror -Wpedantic -Wsign-compare -std=c++17 Agency.cpp Detective.cpp AgencyDriver.cpp
 * 
 * TODO:  fix the code, it seems reasonable, but it currently prints 
 *        "I can't do that you big dummy!"
 */
#include "Agency.h"
#include "Detective.h"  // getting rid of this is likely also a way to fix the ifndef thing...
#include<iostream>
#include<cassert>
using namespace std;

int main()
{
    Agency theAgency = Agency();
    theAgency.hire( Detective( "Sherlock Holmes", 2300 ) );
    theAgency.hire( Detective( "Cordelia Cupp", 300 ) );
    theAgency.hire( Detective( "Jake Peralta", 14 ) );
    
    // someone solved a case
    // specifically cordelia did. so index 1
    theAgency.solveCase(1);
    assert( theAgency.getDetective(1).getCasesSolved() == 301 );

    return 0;
}
