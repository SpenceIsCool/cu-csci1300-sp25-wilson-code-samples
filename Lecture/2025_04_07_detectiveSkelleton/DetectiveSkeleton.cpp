/** 
 * DetectiveSkeleton.cpp
 *
 * return some default vaue for each function
 * don't implement the functions
 *
 * you should be able to build the object file...
 * g++ -std=c++17 -c DetectiveSkeleton.cpp -o DetectiveSkeleton.o
 */
#include "Detective.h"
#include<iostream>
using namespace std;


Detective::Detective()
{
    cout << "TODO" << endl;
    return;
}

Detective::Detective( string name, unsigned short solvedCases )
{
    cout << "TODO" << endl;   
    return;
}

void Detective::print() const
{
    cout << "TODO" << endl;
    return;
}

string Detective::getName() const
{
    cout << "TODO" << endl;
    return "";
}


unsigned short Detective::getSolvedCases() const
{
    cout << "TODO" << endl;
    return 0;
}


/**
 * only set the name 
 * if it is not already set to something
 * don't let someone change the name
 */
void Detective::setName( string name )
{
    cout << "TODO" << endl;
    return;
}


void Detective::setSolvedCases( unsigned short solvedCases )
{
    cout << "TODO" << endl;
    return;
}


