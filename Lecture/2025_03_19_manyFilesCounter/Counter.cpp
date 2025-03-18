/**
 * Counter.cpp
 *
 * an implementation file
 *
 * This shall uphold the contract of Counter.hpp
 * It must define each member function (also called a method) declared in the header file
 */
#include "Counter.hpp"
#include<iostream>
#include<ctime>
using namespace std;


/**
 * Counter
 * make a counter with a random value, limit by MAX
 *
 * our default constructor
 */
Counter::Counter()
{
    srand(time(0));
    // `count` and `MAX` are data members (also called an attribute) of the Counter class
    // Therefore they are implicit paramters of all member functions (also called methods) of the Counter class
    count = std::rand() % MAX;
}


/**
 * Counter
 * make a counter with the startValue, limit by MAX
 */
Counter::Counter( int startValue )
{
    count = startValue % MAX;
}


/**
 * look
 * print the current count
 *
 * an "accessor", it shall NOT change any data members of the class (best practice is to have the `const` there)
 */
void Counter::look() const
{
    // for efficiency count is a char
    // we must first get it as an int
    int i = count;
    cout << "COUNT: " << i << endl;
}


/**
 * click
 * click the button once
 *
 * a "mutator", it could change any data members of the class (not an accessor, no `const`)
 */
void Counter::click()
{
    click( 1 );
}


/**
 * click
 * click the button n times, limit by MAX
 * do not allow negative clicks, hense unsigned int only
 *
 * NOTE: header names the parameter `positiveValue`,
 *       here we name it `n`
 *       that's acceptable
 *       WHY? It's a name. We get to choose it.
 *
 * @param n: the number of times to click the button
 */
void Counter::click( unsigned int n )
{
    // ints can be super long relative to chars...
    n %= MAX;
    // update the count
    count += n;
    // now we can still have a number bigger than MAX...
    count %= MAX;
}


/**
 * reset
 * set the count to 0
 */
void Counter::reset()
{
    count = 0;
}


