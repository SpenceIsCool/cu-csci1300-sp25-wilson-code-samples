#include<iostream>
using namespace std;

int main()
{
    int num;

    cout << "Favorite number?" << endl;
    cin >> num;

    // chaining of `yes` causes if
    if ( num > 0 )
    {
        cout << "positively ";
        // chaining of `no` causes else-if
        if ( num < 10 )
        {
            cout << "small";
        }
        else if ( num < 100 )
        {
            cout << "mid";
        }
        else
        {
            cout << "large";
        }
        
    }
    else
    {
        cout << "Why so negative?";
    }
    cout << endl;
}
