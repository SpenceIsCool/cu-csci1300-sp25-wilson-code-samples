#include<iostream>
using namespace std;

int main( )
{
    cout << "What is your favorite number?" << endl;

    int num;
    cin >> num;

    // cout << "You gave me the number: " << num << endl;

    // ask the question >0?
    if ( num > 0 )
    {
        // cout << "positively" << endl;
        cout << "positively ";
        if ( num < 10 )
        {
            cout << "small" << endl;
        }
        // else { if ...
        else if ( num < 100 )
        {
            cout << "mid" << endl;
        }
        else
        {
            cout << "large" << endl;
        }
    }
    else 
    {
        cout << "Why so negative?" << endl;
    }
}
