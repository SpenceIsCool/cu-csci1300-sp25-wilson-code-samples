#include<iostream>
using namespace std;

int main()
{
    // fancy is a all of the lower case vowels
    string fancy = "aeiou";
    string usersInput;
    cout << "give me a string:" << endl;
    cin >> usersInput;
    
    // this nested loop is a common structure to match between mutliple strings
    // a loop about `i`
    for ( unsigned int i = 0 ; i < usersInput.length() ; i++ )
    {
        // a loop about `j`
        for ( unsigned int j = 0 ; j < fancy.length() ; j++ )
        {
            // note we ask about BOTH `i` and `j`
            if ( usersInput[i] == fancy[j] )
            {
                cout << usersInput[i] << endl;
            }
        }
    }

    return 0;
}



