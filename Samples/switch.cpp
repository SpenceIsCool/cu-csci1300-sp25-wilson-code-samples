#include<iostream>
using namespace std;

int main() {
    char food;
    cout << "give a letter for food: ";
    cin >> food;

    // // note use of ' NOT " for char
    // if ( food == 'A' || food == 'a' ) { cout << "Apple"; } 
    // // note use of toupper for ease
    // else if ( toupper(food) == 'B' ) { cout << "Bannanna"; }
    // else if ( toupper(food) == 'C' ) { cout << "Chocolate"; }
    // else if ( toupper(food) == 'D' ) { cout << "Danish"; }
    // // ...
    
switch (toupper(food)) {
    case 'A':
        cout << "Apple";
        break;
    case 'B':
        cout << "Bannanna";
        break;
    case 'C':
        cout << "Chocolate";
        break;
    case 'D':
        cout << "Danish";
        break;
    default:
        cout << "The kitchen doesn't have that";
}
cout << endl;
}
