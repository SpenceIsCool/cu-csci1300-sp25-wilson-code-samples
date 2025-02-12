#include<iostream>
using namespace std;


int main()
{
    // you can loop on a string
    string mystery;
    char pieceOfTheMystery;
    cout << "give me input without any spaces please:" << endl;
    cin >> mystery;
    for ( int location = 0 ; location < mystery.length( ) ; location++ ) {
        pieceOfTheMystery = mystery[ location ];  // more on this notation after exam
        cout << pieceOfTheMystery << endl;
        // can do more with the pieces of the mystery
    }
}


