/**
 * Agency.cpp
 * 
 * TODO: read build information for Detective.cpp and write similar comments for agency.
 */
#include "Agency.h"  // NOT Agency.cpp!!!! NEVER .cpp!!!!
#include<iostream>
using namespace std;

Agency::Agency(){
    // set all staff to an empty detective
    for ( unsigned short i = 0 ; i < _MAX_HIREABLE ; i ++ )
    {
        staff[i] = Detective();
    }
    staff_index = 0;
}


void Agency::hire( Detective d ){
    staff[staff_index] = d;
    staff_index++;
}


bool Agency::fire( Detective d ){
    return false;
}


void Agency::solveCase( unsigned short index ){
    // compare to the staff_index, is this a valid index?
    if ( staff_index > index )
    {
        cout << "I can't do that you big dummy!" << endl;
        return;
    }
    // if it is, increment the detective's cases solved
    Detective thisOne = staff[ index ];
    unsigned short solvedSoFar = thisOne.getCasesSolved();
    unsigned short newSolved = solvedSoFar + 1;
    thisOne.setCasesSolved( newSolved );
}

Detective Agency::getDetective( unsigned short index )
{
    // what if index out of range?
    // let it return random stuff
    // they are silly to trust my code
    // TODO: handle out of bounds
    return staff[ index ];
}

