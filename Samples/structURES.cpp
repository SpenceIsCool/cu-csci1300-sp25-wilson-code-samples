#include<iostream>
using namespace std;

struct Idk
{
    int stuff;
};  // don't forget the ;

void displayIdk( Idk o1 );
void incrementStuffAlsoBAD( Idk o1 );
void incrementStuffBAD( Idk o1 );
Idk incrementStuffOK( Idk o1 );


int main()
{
    Idk myThing;
    myThing.stuff = 42;
    displayIdk( myThing );

    incrementStuffBAD( myThing );
    cout << "just changing the value isn't enough..." << endl;
    displayIdk( myThing );

    incrementStuffAlsoBAD( myThing );
    cout << "copies don't help either..." << endl;
    displayIdk( myThing );

    myThing = incrementStuffOK( myThing );
    cout << "should have a higher number now..." << endl;
    displayIdk( myThing );

    return 0;
}


void displayIdk( Idk o1 )
{
    cout << "IDK: { stuff: " << o1.stuff << " }" << endl;
}


void incrementStuffAlsoBAD( Idk o1 )
{
    o1.stuff++;
    return;
}


void incrementStuffBAD( Idk o1 )
{
    Idk tmp{ o1.stuff + 1 };
    o1 = tmp;
    return;
}


Idk incrementStuffOK( Idk o1 )
{
    Idk tmp{ o1.stuff + 1 };
    return tmp;
}

