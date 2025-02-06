#include<iostream>
using namespace std;

int main( )
{
    bool alpha;
    // note all non-0 numbers are true
    // NOTE: all non-number strings and chars are false.
    //       I'm confused by this one, would expect the opposite.
    //       probably a nan conversion...
    cout << "enter 1 for true, or 0 for false" << endl;
    cin >> alpha;
    if ( alpha )
    {
        cout << "You answered true" << endl;
    }
    else
    {
        cout << "You answered false" << endl;
    }
}
