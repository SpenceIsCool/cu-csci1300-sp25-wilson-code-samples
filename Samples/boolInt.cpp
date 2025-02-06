#include<iostream>
using namespace std;


int main() {

    int i0, i1, i2;
    i0 = 0;
    i1 = 1;
    i2 = 1300;

    double d0, d1, d2;
    d0 = 0.0;
    d1 = 12.3;
    d2 = -0.0;

    cout << "1 means truthy, 0 means falsy" << endl;
    cout << i0 << ":: " << !!i0 << endl;
    cout << i1 << ":: " << !!i1 << endl;
    cout << i2 << ":: " << !!i2 << endl;
    cout << d0 << ":: " << !!d0 << endl;
    cout << d1 << ":: " << !!d1 << endl;
    cout << d2 << ":: " << !!d2 << endl;
}
