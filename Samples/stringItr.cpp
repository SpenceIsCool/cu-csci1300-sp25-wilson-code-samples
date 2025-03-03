// use -Wsign-compare as a build command
#include<iostream>
using namespace std;

int main()
{
    string x = "hello";
    // // compile error with -Wsign-compare
    // for ( int i = 0 ; i < x.length() ; i++ );

    // these are fine
    for ( unsigned int i = 0 ; i < x.length() ; i++ );
    for ( size_t i = 0 ; i < x.length() ; i++ );
    for ( int i = 0 ; i < (int)x.length() ; i++ );

    return 0;
}
