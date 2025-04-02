/**
 * Detective.h
 * 
 * best practice from the book
 * START: ifndef: if not defined
 * END: endif: end this if block
 * 
 * OBSERVE: all of the code is in this block, so it will only happen once  
 *          the condition is predicated on a variable named DETECTIVE_H
 *          and the first line of the body of the condition defines DETECTIVE_H for us
 */
#ifndef DETECTIVE_H
#define DETECTIVE_H

#include<string>
using namespace std;

class Detective {
public:
    Detective();
    Detective( string n, unsigned short c );
    void show();
    string getName();
    void setName( string newName );
    unsigned short getCasesSolved();
    void setCasesSolved( unsigned short newCases );
private:
    string name;
    unsigned short casesSolved;  // 2^16
};

#endif