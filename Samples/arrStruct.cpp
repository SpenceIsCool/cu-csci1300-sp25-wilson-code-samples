#include<iostream>
using namespace std;

struct Alpha {
    bool bravo;
    int charlie; 
};

int main()
{
    const int DELTA = 2;
    Alpha echo[ DELTA ] = { {true,5}, {false,-10} };
    for ( int i = 0 ; i < DELTA ; i++ )
    {
        Alpha a = echo[ i ];
        cout << a.bravo << echo[i].charlie << endl;
    }
}

