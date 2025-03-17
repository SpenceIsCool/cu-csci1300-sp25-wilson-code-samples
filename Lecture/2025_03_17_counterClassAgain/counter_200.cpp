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
    // Q&A: What is a constructor?
    //      its a specail function of a class
    //      that knows how to make object
    //      that knows how to instantiate the class
    Counter();  // default constructor
    Counter( int n );  // a second constuctor, "overloads" the original
    // Q&A: does the first constructor become obsolete?
    //      we can choose to use either
    //      best practice is to always have a default constructor
    //      common practice is to often nevery actually call it directly
    void look() const;
    void click();
    void click_many( int n );
    void reset();
private:
    // note: count is private
    // following our best practice, we should "encapsulate" the data member
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

    Counter z{ 5 };
    // // because the count is private
    // // we cannot access it directly
    // // we must make public methods to give us access instead
    // cout << z.count << endl;
    z.look();
    z.click_many( 765 );
    z.click_many( -2 );
    z.look( );
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
    // count is an "implicit parameter"
    count = 0;
}

/**
 * Counter( n )
 * let us define a second constructor of our class
 * given a number n, creat a Counter object 
 * initialize the encapsulate `count` to `n`
 */
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
    // // original solution
    // count++;

    // // above was fine, but now we want to only support 2 digit numbers
    // count++;
    // count %= 100; 

    // but let's keep that logic all in one place for easier updates later
    click_many( 1 );
}

void Counter::click_many( int n )
{
    // n shouldn't be negative
    // maybe just ingore it
    if ( n < 0 )
    {
        return;
    }

    count += n;
    // lets only support 2 digit numbers
    count %= 100;
}


// void Counter::click_many( int n )
// {
//     // n shouldn't be negative
//     // maybe just ingore it
//     count += n;
//     /**
//      * here and in the click function, where does `count` come from
//      * This is fancy OOP stuff
//      * it's called an "implicit parmeter" of the function
//      * why? 
//      * `n` is an "explicit parameter", what we are used to
//      * `count` is not stated explicitly. but we know it's in the Counter class
//      */
// }

// void Counter::click_many( int n )
// {
//     // how do we access the private data?
//     // the Counter class has a `count` data member
//     // that is private

//     // // might work, but is there a better way?
//     // for ( int i = 0 ; i < n ; i++ )
//     // {
//     //     // update count
//     //     count++;
//     // }

//     // // set count directly
//     // count = count + n;
//     count += n;
//     return;
// }


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

    cout << "testOverload: >>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
    // TODO
    // Counter y{ };  // calls the default constructor
    Counter y{ 42 }; 
    y.look();

    // clicking a few time, maybe copy and paste

    // // clicking many times, consider a loop
    // // click it 100 times
    // for ( int i = 0 ; i < 100 ; i++ )
    // {
    //     y.click();
    // }

    // maybe this looping to click many times shouldn't actually be here.
    // let's bring it into the class
    y.click_many( 100 );

    y.look();
    cout << "testOverload: <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;

    return;
}

