#include<iostream>
using namespace std;

int main()
{
    int x[5] = { 3, 6, 9, 12, 15 };
    cout << x[2] << endl;
    // cout << x.length() << endl;
    cout << sizeof(x) << endl;
    cout << sizeof(x)/sizeof(x[0]) << endl;

    return 0;
}
