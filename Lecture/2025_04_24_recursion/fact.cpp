#include<iostream>
#include<cassert>
using namespace std;

unsigned int fact( unsigned short n )
{
    // BASE CASE
    if ( n <= 1 )
    {
        return 1;
    }
    // RECURSIVE CASE
    else
    {
        unsigned int nm1, fnm1, fn;
        nm1 = n - 1;
        fnm1 = fact( nm1 );
        fn = n * fnm1;
        return fn;
    }
}


int main()
{
    assert( fact( 0 ) == 1 );
    assert( fact( 1 ) == 1 );
    assert( fact( 2 ) == 2 );
    assert( fact( 3 ) == 6 );
    assert( fact( 4 ) == 24 );
    assert( fact( 5 ) == 120 );
    cout << "$$$$$ ALL TESTS PASSED" << endl;
    return 0;
}


