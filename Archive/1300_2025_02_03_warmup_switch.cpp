#include<iostream>
using namespace std;

int main() {
    int november, mike;
    cout << "Give me a number between 0 and 11" << endl;
    cin >> november;
    if ( 0 <= november && november <= 11 )
    {
        // % - called a modulus
        mike = november % 3;
        switch (mike) {
            case 0:
                cout << "0, 3, 6, 9, ..." << endl;
                break;
            case 1:
                cout << "1, 4, 7, 10, ..." << endl;
                break;
            case 2:
                cout << "2, 5, 8, 11, ..." << endl;
                break;
        }
    }
    else  // if ( 0 > november || november > 11 )
    {
        cout << "NOPE" << endl;
    }
}
