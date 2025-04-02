/** 
 * Detective.cpp
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
    name = "no name known";
    solvedCases = 0;
}

Detective::Detective( string n, unsigned short s )
{
    name = n;
    solvedCases = s;
}

void Detective::print() const
{
    cout << name << " has solved " << solvedCases << " cases." << endl;
}

string Detective::getName()
{
    return name;
}


unsigned short Detective::getSolvedCases()
{
    return solvedCases;
}


void Detective::setName( string newName )
{
    name = newName;
}


void Detective::setSolvedCases( unsigned short newSolvedCases )
{
    solvedCases = newSolvedCases;
}

