/**
 * counter.cpp
 * 
 * our first class definition. Imagine a small handheld counting clicker.
 * There are only a few things that can be done with this clicker
 * 
 * NOTE layout of file
 * - #includes and namespaces
 * - class declaration
 * - main
 * - definition of class member functions
 */


// #includes and namespaces
#include<iostream>
using namespace std;


// class declaration
// at a quick glance we have a sense of what this class can do
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


// main
// here we can make a class and call it's methods
int main()
{
    Counter x{};
    x.look();
    x.click();
    x.click();
    x.look();
    x.reset();
    x.look();
}


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
 * TODO: let us "overload" the constructor
 */
Counter::Counter()
{
    // Where did count come from?!? the function doesn't state it!
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
 * - what if we round at 10 (small cliker) [change count type?]
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

