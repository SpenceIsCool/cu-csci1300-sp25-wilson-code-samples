#include<iostream>
using namespace std;

int main() {
    double grade;
    cout << "what was your grade?";
    cin >> grade;
    if ( grade > 60 ) {
        cout << "Passed ";
        if ( grade > 93 ) {
            cout << "with an A" << endl;
        } else if ( grade > 90 ) {
            cout << "with an A-" << endl;
        } else if ( grade > 87 ) {
            cout << "with a B+" << endl;
        } else if ( grade > 83 ) {
            cout << "with a B" << endl;
        } // ...
    } else {
        cout << "did not pass." << endl;
    }
} 