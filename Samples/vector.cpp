#include<vector>
#include<iostream>
using namespace std;


void showVector( vector<string> s );

int main( )
{
    vector< string > v;
    showVector( v );
    cout << v.max_size() << endl;

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

    for ( int i = 0 ; i < 20 ; i++ )
    {
        v.push_back( "x" + to_string( i ) );
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
        cout << "}" << endl;
    }
    showVector( v );

    cout << endl << endl << " XXXXXX DELETING ALL ELEMENTS " << endl;

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
        cout << "}" << endl;
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
    cout << "}" << endl;
}


