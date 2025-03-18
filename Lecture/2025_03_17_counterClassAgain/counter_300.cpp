/**
 * counter_300.cpp
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
    Counter( );  // default constructor
    Counter( int n );
    void look() const;
    int get_count() const;
    void click();
    void click( int n );
    void reset();
private:
    int count;
    const int MAX = 100;
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
    count = 0;
}

Counter::Counter( int n )
{
    count = n;
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

int Counter::get_count() const
{
    return count;
}


// /**
//  * click
//  * a "mutator", it could change any data members of the class (not an accessor, no `const`)
//  * 
//  * Counter::click
//  * nameOfClass::nameOfMemberFunction
//  * 
//  * explicit parameters: ???
//  * implicit parameters: ???
//  * return value: ???
//  * 
//  * TODO: play with ideas
//  * - what if we round at 100 (a two digit display)
//  * - whta if we have the ability to do a many click?
//  */
// // click doesn't have any parameters...
// // or rather explicitly decalare any parameters
// void Counter::click()
// {
//     // count = count + 1;
//     // count += 1;
//     count++;

//     // count is called an "implicit parameter"
//     // it's a data member of the relevant Counter class
//     // we are in a member function of the Counter class
//     // and so it must be usable

//     // if the class had other data members, are those accessible here?
//     // yes, and let's show it
//     // let's have a max of 99
//     count %= MAX;
// }


void Counter::click()
{
    // count++;
    // count %= MAX;

    click( 1 );
}

// void Counter::click( int n )
// {
//     // // works fine, are there other ways?
//     // for ( int i = 0 ; i < n ; i++ )
//     // {
//     //     count++;
//     // }
//     // count %= MAX;

//     // // call the other click function
//     // for ( int i = 0 ; i < n ; i++ )
//     // {
//     //     click();
//     // }

//     count += n;
//     count %= MAX;
// }

/**
 * click
 * n is an explicit parameter
 * count and MAX are implicit parameters
 * 
 * when we are done clicking the button n times
 * we should have a value between 0 and 99
 */
void Counter::click( int n )
{
    // what if the number is negative?
    // seems like a thing we don't want to let users do
    if ( n < 0 )
    { 
        cout << "NOPE!" << endl;
        return;
    }

    count += n;

    // we could state how many times it resets to 0
    int reset_count = count / MAX;
    cout << "We reset " << reset_count << " times." << endl;

    count %= MAX;

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

    // // click it 105 times
    // // a `for` loop is fine
    // for ( int i = 0 ; i < 105 ; i++ )
    // {
    //     x.click();
    // }

    // maybe I should have another member function
    // define a differnt click function
    // by "overloading" the original defintion
    x.click( 105 );

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

    cout << "testOverload: >>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
    // TODO
    Counter y{ };  // call the default constructor
    y.click( );     // call the basic click
    y.click( 20 );   // call the nicer click
    y.look( );

    Counter z{ y.get_count( ) * 2 };  // call the fancy constructor
    z.look( );
    cout << "testOverload: <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;

    return;
}

