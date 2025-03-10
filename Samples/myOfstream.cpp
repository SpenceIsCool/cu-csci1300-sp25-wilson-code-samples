#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    string x = "hello.txt";
    // will make the file for you
    // ofstream y( x );
    ofstream y;
    y.open( x );
    y << "Hey" << endl;
    y << "sup bro" << endl;
    y.close();

    // what if the file exists but you don't have permissions
    // chmod -w locked.txt
    x = "locked.txt";
    y.open( x );
    if ( y.fail( ) )
    {
        cout << "failed to open " << x << " as expected. It's locked for writing." << endl;
    }
    y.close();

    ifstream z;
    string l;
    z.open( x );
    while ( getline( z, l ) )
    {
        cout << l << endl;
    }
    z.close();


    return 0;
}

