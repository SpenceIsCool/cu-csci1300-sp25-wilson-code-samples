#include<iostream>
using namespace std;

int main ( )
{
    int theirNumber;

    cout << "Hey, what's your favorite number?" << endl;
    cin >> theirNumber;

    // cout << "You said your favorite number is: " << theirNumber << endl;
    if ( theirNumber > 0 )
    {
        // cout << "positively" << endl;
        cout << "positively";
        // if ( theirNumber < 10 )
        // {
        //    cout << "small" << endl;
        // }
        // else if ( theirNumber < 100 )
        // {
        //     cout << "mid" << endl;
        // }
        // else
        // {
        //     cout << "large" << endl;
        // }

        // if ( theirNumber < 10 ) cout << "small" << endl;
        // cout << "and then do more stuff after positively small" << endl;
        // if ( theirNumber < 100 ) cout << "mid" << endl;
        // else cout << "large" << endl;

        if ( theirNumber < 10 )
        {
            cout << "small" << endl;
            cout << "and then do more stuff after positively small" << endl;
        }
        else if ( theirNumber < 100 ) cout << "mid" << endl;
        else cout << "large" << endl;
    }
    else
    {
        cout << "Why so negative?" << endl;
    }
}


