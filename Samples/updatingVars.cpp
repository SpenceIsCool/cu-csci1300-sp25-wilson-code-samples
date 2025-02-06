#include <iostream> // cout, fixed
#include <iomanip> // setprecision
using namespace std;

int main () {
    int x;
    x = 20;
    cout << "   x++: " <<   x++ << endl;
    cout << "   x--: " <<   x-- << endl;
    cout << "   ++x: " <<   ++x << endl;
    cout << "   --x: " <<   --x << endl;
    cout << "x += 2: " ; x += 2 ; cout << x << endl;
    cout << "x -= 2: " ; x -= 2 ; cout << x << endl;
    cout << "x /= 2: " ; x /= 2 ; cout << x << endl;
    cout << "x %= 2: " ; x %= 2 ; cout << x << endl;
    cout << "   x++: " <<   x++ << endl;
    cout << "x *= 2: " ; x *= 2 ; cout << x << endl;
    return 0;
}
