/**
 * Agency.cpp
 * 
 * often won't build this on it's own, but you can for faster builds later on...
 * g++ -Wall -Werror -Wpedantic -Wsign-compare -std=c++17 -c Agency.cpp -o Agency.o
 * 
 * if you open Detective.o it will look like junk
 * it's a file that only your computer can read
 * and you can use it to build things like  AgencyDriver.cpp faster
 */
#include "Agency.h"
#include<iostream>
using namespace std;

Agency::Agency()
{
    _hired_so_far = 0;
    _name = "";

    // Detective staff[_MAX_STAFF];
    //    by default the constuctor for Agency
    //    will call the default constructor 
    //    for Detective
    //    THIS IS WHY you should always define the default constructor

    // static const unsigned short _MAX_STAFF = 10;
    //     already defined statically

}

Agency::Agency( string name )
{
    _name = name;
    _hired_so_far = 0;
}

void Agency::hire( Detective newStaff )
{
    if ( _hired_so_far + 1 == _MAX_STAFF )
    {
        cout << "cannot hire more staff..." << endl;
        return;
    }
    
    _staff[_hired_so_far++] = newStaff;
    return;
}


void Agency::solveNewCase( string detectiveName )
{
    bool found = false;
    for ( unsigned short i = 0 ; i < _hired_so_far ; i++ )
    {
        if ( detectiveName == _staff[i].getName() )
        {
            found = true;
            unsigned short solved = _staff[i].getSolvedCases();
            solved++;
            _staff[i].setSolvedCases( solved );
            break;
        }
    }

    if ( ! found )
    {
        cout << "No such employee exists by the name " 
             << detectiveName 
             << " here." 
             << endl;
    }

    return;
}


void Agency::solveNewCase( unsigned short index )
{
    if ( index > _hired_so_far )
    {
        cout << index
             << " is not a valid index for  " 
             << _name
             << endl;
        return;
    }

    // unsigned short solved = _staff[index].getSolvedCases();
    // solved++;
    // _staff[index].setSolvedCases( solved );
    _staff[index].setSolvedCases( _staff[index].getSolvedCases() + 1);
    return;
}


Detective Agency::getDetective( unsigned short index ) const
{
    if ( index > _hired_so_far )
    {
        cout << index
             << " is not a valid index for  " 
             << _name
             << endl;
        return Detective();
    }

    return _staff[index];
}


Detective Agency::getDetective( string detectiveName ) const
{
    for ( unsigned short i = 0 ; i < _hired_so_far ; i++ )
    {
        if ( detectiveName == _staff[i].getName() )
        {
            return getDetective( i );
        }
    }

    // let the index version handle this for us
    // need to give it a value that is too large
    return getDetective( _MAX_STAFF );
}


void Agency::showAllDetectives() const
{
    cout << _name << ":"<< endl;
    if ( _hired_so_far == 0 )
    {
        cout << "Has no staff" << endl;
    }
    else
    {
        for ( int i = 0 ; i < _hired_so_far ; i++ )
        {
            _staff[i].print();
        }
    }
    cout << endl;
    return;
}

