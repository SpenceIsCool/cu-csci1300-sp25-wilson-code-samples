// Agency.h
#include "Detective.h"

class Agency
{
public:
    Agency();
    void hire( Detective newStaff );
    void solveNewCase( string detectiveName );
    void showAllDetectives() const;
private:
    static const unsigned short _MAX_STAFF = 10;
    Detective staff[_MAX_STAFF];
    unsigned short hired_so_far;
};

