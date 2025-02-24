#include<iostream>
using namespace std;


int main()
{
    string x;
    cout << "Please enter the string 'hello world'" << endl;
    getline( cin, x );
    cout << "x got through getline. printing x: " << x << endl;
    for ( unsigned int i = 0 ; i < x.length( ) ; i++ ) {
        cout << x.substr( i, x.length( ) - i ) << endl; 
    }

    cout << "Please enter the string 'hello world'" << endl;
    cin >> x;
    cout << "x got through >>. printing x: " << x << endl;
    cin >> x;
    cout << "x got through >>. printing x: " << x << endl;

}


