#include<iostream>
#include<cmath>
using namespace std;


// I want to write a function
// that squares a number
// given a number, get me a new number
// int to int
int squareThis( int theThingToSquare )
{
    // return theThingToSquare * theThingToSquare;
    return pow( theThingToSquare, 2 );
}

bool isEven( int num )
{
    // return !( num % 2 );
    return num % 2 == 0;
    // if ( num % 2 == 0 )
    // {
    //     return true;
    // }
    // else
    // {
    //     return false;
    // }
}

// void means return nothing
// i can write code that does that
// typically for printing
// can sere other purposes
void isEvenFancy( int x ) 
{
    if ( isEven( x ) )
    {
        cout << x << " is even." << endl;
    }
    else
    {
        cout << x << " is odd." << endl;
    }

}

int main() 
{
    bool b;
    b = isEven( 10 );
    cout << b << endl;
    b = isEven( 15 );
    cout << b << endl;

    isEvenFancy( 10 );
    // int input, output, expected;
    // input = 10;
    // output = squareThis( input );
    // expected = 100;

    // cout << "EXPECTED: " << expected << endl;
    // cout << "GOT:      " << output << endl;
}
