#include<vector>
#include<iostream>
using namespace std;


void showVector( vector<string> s );

int main( )
{
    cout << "DISCLAIMER: the following code has obsertavtions (OBSERVE)" << endl
         << "            each is based on 'undefined behavior' or 'UB'" << endl
         << "            meaning that your computer might behave differently" << endl
         << "            if so, update the obeservations for your records" << endl
         << "            and let us know on Ed what you discover about your computer" << endl;


    vector< string > v;
    showVector( v );

    cout << endl
         << endl
         << ">>>> adding and delting some string" << endl
         << "OBSERVE: using a function to print the vector" << endl
         << "         causing the vector to force a resize of its capacity" << endl;
    v.push_back( "hello" );
    showVector( v );

    v.push_back( "hey" );
    showVector( v );

    v.push_back( "sup" );
    showVector( v );

    v.push_back( "howdy" );
    showVector( v );

    v.insert( v.begin( ) + 1, v.back( ) );
    showVector( v );

    v.erase( v.begin( ) + 3 );
    showVector( v );
    while ( v.size() != 0 )
    {
        v.pop_back();
        showVector( v );
    }


    cout << endl
         << endl
         << "$$$$ not using a function to show anymore, doing in-line" << endl
         << "OBSERVE: starts at capacity 8" << endl
         << "         when 9th element is added doubles to 16" << endl
         << "         when 17th element is added doubles to 32" << endl;

    for ( int i = 1 ; i < 20 ; i++ )
    {
        v.push_back( "x" + to_string( i ) );
        // do this inline so my computer doesn't force a resize event
        cout << "{ ";
        for ( unsigned long i = 0 ; i < v.size( ) ; i++ )
        {
            cout << v.at( i ) << ", ";
        }
        for ( unsigned long i = v.size( ) ; i < v.capacity( ) ; i++ )
        {
            cout << "__ , ";
        }
        cout << "} [capacity: " << v.capacity() << "]" << endl;
    }
    showVector( v );

    cout << endl
         << endl
         << " XXXXXX DELETING ALL ELEMENTS " << endl
         << "OBSERVE: capacity is not automatically shrinking" << endl;
    while ( v.size() != 0 )
    {
        v.pop_back();
        // do this inline to show the extra space!
        cout << "{ ";
        for ( unsigned long i = 0 ; i < v.size( ) ; i++ )
        {
            cout << v.at( i ) << ", ";
        }
        for ( unsigned long i = v.size( ) ; i < v.capacity( ) ; i++ )
        {
            cout << "__ , ";
        }
        cout << "} [capacity: " << v.capacity() << "]" << endl;
    }

    return 0;
}


void showVector( vector<string> s )
{
    cout << "{ ";
    for ( unsigned long i = 0 ; i < s.size( ) ; i++ )
    {
        cout << s.at( i ) << ", ";
    }
    // won't ever run on my computer
    // passing the vector to a function is forcing a resize event
    for ( unsigned long i = s.size( ) ; i < s.capacity( ) ; i++ )
    {
        cout << "__ , ";
    }
    cout << "} [capacity: " << s.capacity() << "]" << endl;
}


