#include<iostream>
using namespace std;


int main()
{
    cout << "the char of '0' is ";
    if ( false || '0' )
    {
        cout << "TRUTHY";
    }
    else
    {
        cout << "FALSY";
    }
    cout << endl;

    cout << "the int of 0 is ";
    if ( false || 0 )
    {
        cout << "TRUTHY";
    }
    else
    {
        cout << "FALSY";
    }
    cout << endl;
}
