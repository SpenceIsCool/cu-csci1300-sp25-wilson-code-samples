/** 
 * Detective.cpp
 * 
 * often won't build this on it's own, but you can for faster builds later on...
 * g++ -Wall -Werror -Wpedantic -Wsign-compare -std=c++17 -c Detective.cpp -o Detective.o
 * 
 * if you open Detective.o it will look like junk
 * it's a file that only your computer can read
 * and you can use it to build things like DetectiveDriver.cpp and AgencyDriver.cpp faster
 * 
 * defines all of the member functions that were declared in Detective.h
 * be sure to prefix the function name with `Detective::`
 * 
 * best practice is to have a separate header file from the source file
 * this allows us to change out implimentations if we need to 
 * having a sigle header file
 * and maybe many source sfiles based on different production needs
 * Think about "modularity"
 */
#include "Detective.h"
#include<iostream>
using namespace std;


Detective::Detective()
{
    _name = "";
    _solvedCases = 0;
}

Detective::Detective( string name, unsigned short solvedCases )
{
    _name = name;
    _solvedCases = solvedCases;
}

void Detective::print() const
{
    cout << _name << " has solved " << _solvedCases << " cases." << endl;
}

string Detective::getName() const
{
    return _name;
}


unsigned short Detective::getSolvedCases() const
{
    return _solvedCases;
}


void Detective::setName( string name )
{
    // if ( name == "" )  // that's the explicit parameter above
    // NOT the data member
    if ( _name == "" )
    {
        _name = name;
    }
    else
    {
        cout << "A detective cannot change their name until after they" << endl;
    }
    
}


void Detective::setSolvedCases( unsigned short solvedCases )
{
    _solvedCases = solvedCases;
}


