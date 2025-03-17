/**
 * counter.cpp
 * 
 * our first class definition. Imagine a small handheld counting clicker.
 * There are only a few things that can be done with this clicker
 * 
 * NOTE layout of file
 * - #includes and namespaces
 * - class declaration
 * - other function declarations
 * - main
 * - definition of class member functions
 * - other function definitions
 */


//
// #includes and namespaces
// 
#include<iostream>
using namespace std;


//
// class declaration
//
// at a quick glance we have a sense of what this class can do
/**
 * Counter
 * TODO: later: a 2 digit counter can show numbers 0 - 99, be efficient
 * TODO: later: get/set
 * TODO: last: document the class expectations
 */
class Counter
{
public:
    Counter();  // default constructor
    void look() const;
    void click();
    void reset();
private:
    int count;
};  // don't forget the semi-colon


//
// other function declarations
//
void testDefault( );
void testOverload( );


//
// main
//
// here we can make a class and call it's methods
int main()
{
    testDefault( );
    testOverload( );
}


//
// definition of class member functions
//
/**
 * Counter
 * The "default constructor"
 * Like any "constructor" this makes an object for us.
 * We get to specify the behavior, like starting with a random value or starting with 0.
 * 
 * no "explicit parameters"
 * one "implicit parameter" named `count` (the data member of the class)
 * "returns" a Counter object
 * 
 * Counter::Counter
 * nameOfClass::nameOfMemberFunction
 * 
 * TODO: now: let us "overload" the constructor
 */
Counter::Counter()
{
    // Where did count come from?!? the function doesn't state it!
    // ???
    count = 0;
}


/**
 * look
 * an "accessor", it shall NOT change any data members of the class (best practice is to have the `const` there)
 * 
 * Counter::look
 * nameOfClass::nameOfMemberFunction
 * 
 * explicit parameters: ???
 * implicit parameters: ???
 * return value: ???
 */
void Counter::look() const
{
    cout << "COUNT: " << count << endl;
}


/**
 * click
 * a "mutator", it could change any data members of the class (not an accessor, no `const`)
 * 
 * Counter::click
 * nameOfClass::nameOfMemberFunction
 * 
 * explicit parameters: ???
 * implicit parameters: ???
 * return value: ???
 * 
 * TODO: play with ideas
 * - what if we round at 100 (a two digit display)
 * - whta if we have the ability to do a many click?
 */
void Counter::click()
{
    count++;
}


/**
 * reset
 * another "mutator", used to change the count value back to 0...
 * 
 * Counter::look
 * nameOfClass::nameOfMemberFunction
 * 
 * explicit parameters: ???
 * implicit parameters: ???
 * return value: ???
 */
void Counter::reset()
{
    count = 0;
}


//
// other function definitions
//
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


void testOverload( )
{
    cout << endl << endl << endl
         << "TODO: test the overloading of the constructor" << endl
         << endl;

    cout << "testOverload: testDefault: >>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
    // TODO
    cout << "testOverload: testDefault: <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;

    return;
}

