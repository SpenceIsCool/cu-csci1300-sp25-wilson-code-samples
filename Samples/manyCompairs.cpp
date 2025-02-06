#include<iostream>
using namespace std;

int main() {
    int x;
    cout << "Please give a value for x: ";
    cin >> x;
    if ( 10 < x < 30 ) {
        cout << "It is TRUE that: 10 < " << x << " < 30" << endl;
    } else {
        cout << "that's false and it must be true that 10 >= " << x << " OR: 30 <= " << x << endl;
    } 
}
