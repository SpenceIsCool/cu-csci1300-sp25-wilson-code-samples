/**
 * main.cpp
 *
 * a file to use our Counter class and test it out
 *
 * build command:
 * g++ -o runMe.out -Wall -Werror -Wsign-compare -Wpedantic -std=c++17 Counter.cpp main.cpp
 *
 * run command:
 * ./runMe.out
 */
#include "Counter.h"  // NOT Counter.cpp
#include<iostream>
using namespace std;


void testDefault( );
void testAutomation( );


int main()
{
    testDefault( );
    testAutomation( );
}


void testDefault( )
{
    cout << endl << endl << endl
         << "testDefault:" << endl
         // \t is a tab character
         << "\t1. I will create a counter object, and look at it once" << endl
         << "\t2. click it twice, then look at it again" << endl
         << "\t3. reset it, then look at it again" << endl
         << endl;

    cout << "BEGIN: testDefault: >>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
    Counter x{};
    x.look();
    x.click();
    x.click();
    x.look();
    x.reset();
    x.look();
    cout << "END: testDefault: <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;

    return;
}


void testAutomation( )
{
    // TODO: add a get_count method to the class,
    //       then use assert (from cassert) here to test expected results
    //       try to find the edge cases, like why we have n %= MAX in click(n)...
}


