#include<iostream>
using namespace std;

int main()
{
string x = "hello";
cout << x << endl;
string y = x.substr( 0, 2 );
cout << y << endl;  // prints "he"
string z = x.substr( 2, 3 );
cout << z << endl;  // prints "llo"
return 0;
}

