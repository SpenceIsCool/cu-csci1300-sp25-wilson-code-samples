/**
 * Detective.cpp
 * 
 * often won't build this on it's own, but you can for faster builds later on...
 * g++ -Wall -Werror -Wpedantic -Wsign-compare -std=c++17 -c Detective.cpp -o Detective.o
 * 
 * if you open Detective.o it will look like junk
 * it's a file that only your computer can read
 * and you can use it to build things like DetectiveDriver.cpp and AgencyDriver.cpp faster
 */
#include "Detective.h"
#include<iostream>
using namespace std;

Detective::Detective() {
    name = "UNASSIGNED";
    casesSolved = 0;
}

Detective::Detective( string n, unsigned short c )
{
    name = n;
    casesSolved = c;
}

void Detective::show()
{
    cout << "The Detective " << name << " has solved " << casesSolved << " cases." << endl;
}

string Detective::getName(){
    return name;
}
void Detective::setName( string newName ){
    name = newName;
}
unsigned short Detective::getCasesSolved(){
    return casesSolved;
}
void Detective::setCasesSolved( unsigned short newCases ){
    casesSolved = newCases;
}
