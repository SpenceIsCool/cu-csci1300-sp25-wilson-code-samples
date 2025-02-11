#include<iostream>
using namespace std;

int main()
{
    string idk = "Hello there";
    int toInvestigate = 0;
    // get a length of a string
    // using the `.length()` function (called a method)
    while ( toInvestigate < idk.length() )
    {
        // cout << "This is the song that never ends... It just goes on and on and on" << endl;
        char idkInvestigated = idk[toInvestigate];
        cout << idkInvestigated << endl;
        toInvestigate++;
    }

    int x = 0;
    while ( x < 5 )
    {
        int y = 0;
        while ( y < 2 )
        {
            cout << x << y << endl;
            y++;  // y += 1;
        }

        x++;
    }



    return 0;
}