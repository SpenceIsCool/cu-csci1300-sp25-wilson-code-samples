#include<iostream>
using namespace std;

struct Thing
{
    int member1;
    int member2[ 3 ];
};


void foo( Thing t )
{
    cout << "FOO: the member2 should not change when just passing the struct" << endl;
    for ( int i = 0 ; i < 3 ; i++ )
    {
        t.member2[i]++;
    }
}

void bar( int a[] )
{
    cout << "BAR: the member2 can change if passing it directly" << endl;
    for ( int i = 0 ; i < 3 ; i++ )
    {
        a[i]++;
    }
}

void showThing( Thing t )
{
    cout << "THING:"
         << endl
         << "  member1: " << t.member1
         << endl
         << "  member2: { " << t.member2[0] << ", " << t.member2[1] << ", " << t.member2[2] << " }"
         << endl
         << endl
         << endl;
}

int main( )
{
    Thing myValue{ 5, { 2, 4, 6 } };
    showThing( myValue );
    foo( myValue );
    showThing( myValue );
    bar( myValue.member2 );
    showThing( myValue );
    return 0;
}


