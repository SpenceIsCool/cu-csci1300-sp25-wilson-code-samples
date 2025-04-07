/**
 * rand.cpp
 *
 * using rand, generate a pseudo-random number
 * use this number to simulate flipping a fair coin
 * print Heads half of the time and Tails half of the time
 * with enough coin flips we should find that coin toss is fair
 */
#include<iostream>  // cout, cin
#include<cstdlib>  // srand, rand
// NOT totally required to include ctime
// but listed separately here so you know where time() comes from
#include<ctime>  // time
using namespace std;


int main( )
{
    // srand: seed random
    //        use the current time as the seed
    //        this should make it random each time you launch the program
    //        if you forget this step (or comment it out)
    //        then the head/tail pattern will be the same each time you run the program
    srand( time( 0 ) );

    while ( true )
    {
        // rand() % 100 get a random number [0 to 99]
        // see if that number is greater than 50 (only half of the time by nature of rand() )
        if ( rand() % 100 > 50 )
        {
            cout << "Heads" << endl;
        }
        else 
        {
            cout << "Tails" << endl;
        }

        cout << "keep going [1/0]?" << endl;
        string userResponse;
        cin >> userResponse;
        if ( userResponse != "1" )
        {
            break;  // end the while loop
        }
    }


    return 0;
}


