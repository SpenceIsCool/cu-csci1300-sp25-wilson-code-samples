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

class Detective
{
public:
    Detective();
    Detective( string name, unsigned short solvedCases );
    void print() const;
    string getName() const;
    unsigned short getSolvedCases() const;
    // only set name if the name is not already set
    void setName( string name );
    void setSolvedCases( unsigned short solvedCases );
private:
    string _name;
    unsigned short _solvedCases;
    // TODO: EvilVillan theirNemisis
};


#endif
