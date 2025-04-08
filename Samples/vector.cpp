/**
 * vector.cpp
 * most of the things you should know about vectors
 * and some things you really don't need to know
 */
#include<vector>
#include<iostream>
using namespace std;


void showVectorByValue( vector<string> v );
void showVectorByValue( vector<int> v );
vector<int> incrementAllByOneByValue( vector<int> v );
void handleStringsVectorByValue( );
void handleIntsVectorByValue( );



// NOTE: you are not allowed to use references in Project 2 for CSCI 1300
// but if you wanted an example of it, here it is
void showVectorByReference( vector<int>& v );
void incrementAllByOneByReference( vector<int>& v );
void handleIntsVectorByReference( );



int main( )
{
    handleStringsVectorByValue( );
    handleIntsVectorByValue( );
    handleIntsVectorByReference( );

    return 0;
}


/**
 * showVectorByValue
 * a good enough way to print all the elements of a 1D vector
 */
void showVectorByValue( vector<string> v )
{
    cout << "{ ";
    // for-each loop, common and best-practice of vectors
    for ( string x : v )
    {
        cout << x << ", ";
    }
    cout << "}" << endl;
}


/**
 * showVectorByValue
 * another way to print all the elements of a 1D vector
 * uses pointers (don't use this for your project, just use the for-each loop)
 */
void showVectorByValue( vector<int> v )
{
    cout << "{ ";
    for ( unsigned int i = 0 ; i < v.size() ; i++ )
    {
        cout << v.at(i) << ", ";
    }
    cout << "}" << endl;
}


/**
 * incrementAllByOneByValue
 */
vector<int> incrementAllByOneByValue( vector<int> v )
{
    // careful about using insert in a loop
    // lots of details here:
    // https://stackoverflow.com/questions/60349386/c-how-to-loop-through-integer-elements-in-a-vector
    // avoided for this example
    
    for ( unsigned int offset = 0 ; offset < v.size( ) ; offset++ )
    {
        // // get the value
        // int x = v.at( offset );
        // // increment the value
        // x++;
        // // put the incremented value in the current place and shift stuff around
        // v.insert( v.begin() + offset, x );
        // // the old value was shifted around, delete it.
        // v.erase( v.begin() + offset + 1 );

        // // shorter
        // v.insert( v.begin() + offset, v.at(offset) + 1  );
        // v.erase( v.begin() + offset + 1 );

        // much cleaner and more common
        v.at( offset )++;
    }

    // don't forget to return the vector!
    // we have pass-by-value here!
    return v;
}


void handleStringsVectorByValue( )
{
    cout << endl
         << endl
         << ">>>> adding and deleting some string" << endl
         << "OBSERVE: using a function to print the vector uses pass-by-value" << endl
         << "         causing the vector to force a resize of its capacity" << endl;
         
    vector< string > v;
    showVectorByValue( v );

    v.push_back( "hello" );
    showVectorByValue( v );

    v.push_back( "hey" );
    showVectorByValue( v );

    v.push_back( "sup" );
    showVectorByValue( v );

    v.push_back( "howdy" );
    showVectorByValue( v );

    v.insert( v.begin( ) + 1, v.back( ) );
    showVectorByValue( v );

    v.erase( v.begin( ) + 3 );
    showVectorByValue( v );
    while ( v.size() != 0 )
    {
        v.pop_back();
        showVectorByValue( v );
    }

    return;
}


void handleIntsVectorByValue( )
{
    cout << endl
         << endl
         << "$$$$$ adding many multiples of 5" << endl
         << "OBSERVE: using a function to print the vector uses pass-by-value" << endl
         << "         causing the vector to force a resize of its capacity" << endl
         << "         doesn't matter if the vector holds strings or ints, pass-by-value is the same" << endl;
         
    vector< int > v;
    for ( int i = 1 ; i < 6 ; i++ )
    {
        v.push_back( i * 5 );
        showVectorByValue( v );
    }


    cout << "$$$$$ incrementing all values by 1" << endl;
    v = incrementAllByOneByValue( v );
    showVectorByValue( v );

    cout << "$$$$$ DELETING ALL ELEMENTS starting from the front " << endl;
    while ( v.size() != 0 )
    {
        v.erase( v.begin() + 0);
        showVectorByValue( v );
    }
}




/**
 * showVectorByReference
 * here `&` means we are passing the vector by reference
 * you cannot use this on your project...
 */
void showVectorByReference( vector<int>& v )
{
    cout << "{ ";
    // don't use auto... bad practice for CSCI 1300
    for ( auto x: v )
    {
        cout << x << ", ";
    }
    for ( auto i = v.size() ; i < v.capacity() ; i++ )
    {
        cout << "__, ";
    }
    cout << "} [capacity:" << v.capacity() << "]" << endl;
    return;
}


/**
 * incrementAllByOneByReference
 * here `&` means we are passing the vector by reference
 * you cannot use this on your project...
 */
void incrementAllByOneByReference( vector<int>& v )
{
    for ( unsigned int i = 0 ; i < v.size() ; i ++ )
    {
        v.at(i)++;
    }
    // we no longer return anything, the reference is used to change the original value.
}

void handleIntsVectorByReference( )
{
    cout << endl
         << endl
         << "XXXXX using references and powers of 2" << endl
         << "DO NOT use references like this on your project" << endl
         << "       but be advised that this is possible" << endl
         << "DISCLAIMER: the following obsertavtions are is based on 'undefined behavior' or 'UB'" << endl
         << "            meaning that your computer might behave differently" << endl
         << "            if so, update the obeservations for your records" << endl
         << "            and let us know on Ed what you discover about your computer" << endl
         << "OBSERVE: the vector capacity is doubling to a local power of 2 as needed" << endl
         << "         the vector capacity doesn't shrink" << endl;          
    vector< int > v;
    for ( int i = 1 ; i < 20 ; i++ )
    {
        v.push_back( pow(2, i) );
        showVectorByReference( v );
    }

    cout << "$$$$$ incrementing each value by 1 " << endl;
    incrementAllByOneByReference( v );
    showVectorByReference( v );

    cout << "$$$$$ DELETING ALL ELEMENTS starting from the front " << endl;
    while ( v.size() != 0 )
    {
        v.erase( v.begin() + 0);
        showVectorByReference( v );
    }
}

