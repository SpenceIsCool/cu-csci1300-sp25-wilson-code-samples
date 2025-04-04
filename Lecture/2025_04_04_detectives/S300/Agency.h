/**
 * Agency.h
 * 
 * best practice from the book
 * START: ifndef: if not defined
 * END: endif: end this if block
 * 
 * OBSERVE: all of the code is in this block, so it will only happen once  
 *          the condition is predicated on a variable named DETECTIVE_H
 *          and the first line of the body of the condition defines DETECTIVE_H for us
 */
#ifndef AGENCY_H
#define AGENCY_H


#include "Detective.h"
#include<string>

class Agency
{
public:
    Agency();
    Agency( string name );
    // TODO: Agency( staff )
    void hire( Detective newStaff );
    void solveNewCase( string detectiveName );
    void solveNewCase( unsigned short index );
    void showAllDetectives() const;
    Detective getDetective( unsigned short index ) const;
    Detective getDetective( string detectiveName ) const;
    // TODO: setStaff
    void setStaff( Detective staff[], int num_staff );
private:
    static const unsigned short _MAX_STAFF = 10;
    string _name;
    Detective _staff[_MAX_STAFF];
    unsigned short _hired_so_far;
};


#endif
