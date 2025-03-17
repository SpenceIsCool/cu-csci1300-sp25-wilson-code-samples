#include<iostream>
using namespace std;


int simple_loop( )
{
    int x = 1;
    for ( int i = 0 ; i < 5 ; i++ )
    {
        x *= 2;
    }
    return x;
}

int nested_loop( )
{
    int x = 0;
    for ( int y = 0 ; y <= 5 ; y++ ) {
        for ( int z = 2; z > 0 ; z-- ) {
            x = z + y;
        }
    }
    return x;
}

int main( )
{
    cout << "simple_loop: " << simple_loop( ) << endl;
    cout << "nested_loop: " << nested_loop( ) << endl;
    return 0;
}