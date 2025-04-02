// Agency.h
/**
 * Agency.h
 * 
 * TODO: see Detective.h and replicate this ifndef, define, endif for the Agency
 */
#include "Detective.h"  // NOT Agency.cpp!!!! NEVER .cpp!!!!

class Agency 
{
public:
    Agency();
    void hire( Detective d );
    bool fire( Detective d );
    void solveCase( unsigned short index );
    Detective getDetective( unsigned short index );
private:
    static const unsigned short _MAX_HIREABLE = 50;
    unsigned short staff_index;
    Detective staff[_MAX_HIREABLE];
};
