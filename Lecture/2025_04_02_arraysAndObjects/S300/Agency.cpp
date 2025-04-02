// Agency.cpp
#include "Agency.h"

Agency::Agency()
{
    hired_so_far = 0;

    // Detective staff[_MAX_STAFF];
    //    by default the constuctor for Agency
    //    will call the default constructor 
    //    for Detective
    //    THIS IS WHY you should always define the default constructor

    // static const unsigned short _MAX_STAFF = 10;
    //     already defined statically

}


void Agency::hire( Detective newStaff )
{
    staff[hired_so_far] = newStaff;
    hired_so_far++;
    return;
}


void Agency::solveNewCase( string detectiveName )
{
    // TODO:
    // if this detective exists
    // increment it's cases solved
    return;
}


void Agency::showAllDetectives() const
{
    for ( int i = 0 ; i < hired_so_far ; i++ )
    {
        staff[i].print();
    }
    return;
}

