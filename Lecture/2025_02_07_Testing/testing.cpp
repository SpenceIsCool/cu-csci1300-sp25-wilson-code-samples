/**
 * This document is a series of code to demonstrate test driven development (TDD) practices
 * RECALL how to (un)comment many lines of code
 *   1. highlight the lines
 *   2. ctrl + /
 * 
 * I hope this helps. Start at the bottom and build to the top.
 * 
 * LIVE at lecture, I will add additional notes. They will be uploaded for your review if you're interested.
 */













// // cleanup the code
// #include<iostream>  // cout, endl
// #include <cassert>  // assert
// using namespace std;

// bool isEven( int num );
// void testIsEven();


// int main()
// {
//     testIsEven();
//     return 0;
// }

// /**
//  * isEven
//  * given a number determine if that number is even or odd
//  * 
//  * @param num: the number of interst as an int
//  * @returns: true if num is even, else false
//  */
// bool isEven( int num )
// {
//     // if ( c ) return true else return false is the same as return c
//     return num % 2 == 0;
// }

// /**
//  * testIsEven
//  * given nothing, return nothing. use asserts to test isEven
//  */
// void testIsEven( )
// {
//     assert( isEven( -2 ) == true );
//     assert( isEven( -1 ) == false );
//     assert( isEven( 0 ) == true );
//     assert( !isEven( 1 ) );  
//     assert( isEven( 2 ) );
//     assert( !isEven( 3 ) );
//     assert( isEven( 4 ) );
//     assert( !isEven( 5 ) );
//     return;
// }



























// // now start to generalize the code
// #include<iostream>  // cout, endl
// #include <cassert>  // assert
// using namespace std;

// bool isEven( int num );
// void testIsEven();


// int main()
// {
//     testIsEven();
//     return 0;
// }


// bool isEven( int num )
// {
//     // ..., -2, 0, 2, 4, .... generally 2*k for some number k
//     // maybe `%` will help us do that division
//     if ( num % 2 == 0 )
//     {
//         return true;
//     }
//     // all other numbers... generally 2*k + 1 for some number k
//     else
//     {
//         return false;
//     }
// }


// void testIsEven( )
// {
//     assert( isEven( -2 ) == true );
//     assert( isEven( -1 ) == false );
//     assert( isEven( 0 ) == true );
//     assert( !isEven( 1 ) );  
//     assert( isEven( 2 ) );
//     assert( !isEven( 3 ) );
//     assert( isEven( 4 ) );
//     assert( !isEven( 5 ) );
//     return;
// }

















// // start to write more intersting tests
// #include<iostream>  // cout, endl
// #include <cassert>  // assert
// using namespace std;

// bool isEven( int num );
// void testIsEven();


// int main()
// {
//     testIsEven();
//     return 0;
// }


// bool isEven( int num )
// {
//     if ( num == 2 || num == 4 )
//     {
//         return true;
//     }
//     else if ( num == 1 || num == 3 || num == 5 )
//     {
//         return false;
//     }

//     return false;
// }


// void testIsEven( )
// {
//     // already had
//     assert( !isEven( 1 ) );  
//     assert( isEven( 2 ) );
//     assert( !isEven( 3 ) );
//     assert( isEven( 4 ) );
//     assert( !isEven( 5 ) );
    
//     // new tests...
//     assert( isEven( 0 ) == true );
//     assert( isEven( -1 ) == false );
//     assert( isEven( -2 ) == true );
//     // note we are now not passing all tests
//     return;
// }
















// // write better code
// #include<iostream>  // cout, endl
// #include <cassert>  // assert
// using namespace std;

// bool isEven( int num );
// void testIsEven();


// int main()
// {
//     testIsEven();
//     return 0;
// }


// bool isEven( int num )
// {
//     // perhaps this seems silly 
//     // but just hard code to your tests for now
//     if ( num == 2 || num == 4 )
//     {
//         return true;
//     }
//     else if ( num == 1 || num == 3 || num == 5 )
//     {
//         return false;
//     }

//     // still good to have a default return
//     return false;
// }


// void testIsEven( )
// {
//     assert( !isEven( 1 ) );  

//     assert( isEven( 2 ) );
//     assert( isEven( 4 ) );

//     assert( !isEven( 3 ) );
//     assert( !isEven( 5 ) );
    
//     return;
// }















// // write better tests and fail them
// #include<iostream>  // cout, endl
// #include <cassert>  // assert
// using namespace std;

// bool isEven( int num );
// void testIsEven();


// int main()
// {
//     testIsEven();
//     return 0;
// }


// bool isEven( int num )
// {
//     return false;
// }


// void testIsEven( )
// {
//     assert( isEven( 1 ) == false );
//     assert( false == isEven( 1 ) );
//     assert( !isEven( 1 ) );  // the rest will be in this style

//     // some true tests
//     assert( isEven( 2 ) );
//     assert( isEven( 4 ) );

//     // some more false tests
//     assert( !isEven( 3 ) );
//     assert( !isEven( 5 ) );

//     return;
// }




















// // write code to pass the tests
// #include<iostream>  // cout, endl
// #include <cassert>  // assert
// using namespace std;

// bool isEven( int num );
// void testIsEven();


// int main()
// {
//     testIsEven();
//     return 0;
// }


// bool isEven( int num )
// {
//     // the tests say always return false...
//     return false;
// }


// void testIsEven( )
// {
//     assert( isEven( 1 ) == false );
//     assert( false == isEven( 1 ) );
//     assert( !isEven( 1 ) );
//     return;
// }























// // write tests that you should fail
// #include<iostream>  // cout, endl
// #include <cassert>  // assert
// using namespace std;

// bool isEven( int num );
// void testIsEven();


// int main()
// {
//     testIsEven();
//     return 0;
// }


// bool isEven( int num )
// {
//     return true;
// }


// void testIsEven( )
// {
//     // many ways to write the same test...
//     // we write one test before we code
//     // the isEven function...
//     // we make sure we can run the code....
//     assert( isEven( 1 ) == false );
//     assert( false == isEven( 1 ) );
//     assert( !isEven( 1 ) );
//     return;
// }

















// // get setup with the related function(s)
// #include<iostream>  // cout, endl
// #include <cassert>  // assert
// using namespace std;

// // declare the function(s)
// // doing it here makes it so that I don't have to worry
// // about ordering later on
// // lookup "forward declaration" in C++
// // ADVANCED: Lookup "type safety" in C++
// bool isEven( int num );
// void testIsEven();


// // define main
// int main()
// {
//     testIsEven();
//     return 0;
// }

// // define the functions
// /**
//  * isEven
//  * given a number determine if that number is even or odd
//  * 
//  * @param num: the number of interst as an int
//  * @returns: true if num is even, else false
//  */
// bool isEven( int num )
// {
//     // put a default return in for now
//     return true;
// }

// /**
//  * testIsEven
//  * given nothing, return nothing. use asserts to test isEven
//  */
// void testIsEven( )
// {
//     return;
// }
















// it's nice to start with hello world
#include<iostream>  // cout, endl
using namespace std;

int main()
{
    cout << "Hello, World!" << endl;
}
