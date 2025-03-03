#include<iostream>
using namespace std;

int main()
{
    char x[5] = { 'h', 'e', 'l', 'l', 'o' };
    cout << x[2] << endl;
    // cout << x.length() << endl;
    cout << sizeof(x) << endl;
    cout << sizeof(x)/sizeof(x[0]) << endl;
    return 0;
}
