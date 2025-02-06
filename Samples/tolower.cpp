#include<iostream>
using namespace std;

int main() {

    // this is not valid code. It won't compile. G++ will fail​

    char x, y;
    cout << "letter please: " << endl;
    cin >> x;
    y = tolower(x);
    cout << y << endl;
}
