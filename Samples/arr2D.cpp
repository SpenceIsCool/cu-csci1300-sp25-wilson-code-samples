#include<iostream>
using namespace std;

int main()
{
    // 2D array
    double idk[5][2] = { {1,2}, {3.1415,6.283} };
    // ROOM for 3 more rows

    cout << "double idk[5][2] = { {1,2}, {3.1415,6.283} };" << endl;
    cout << "idk[0][0]: " << idk[0][0] << endl;
    cout << "idk[1][1]: " << idk[1][1] << endl;
    cout << "sizeof(idk): " << sizeof(idk) << endl;
    cout << "double_size * rows * cols = 8*5*2 = " << 8*5*2 << endl;
    return 0;
}
