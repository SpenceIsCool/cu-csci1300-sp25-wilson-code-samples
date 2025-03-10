#include<iostream>
using namespace std;

class Idk
{
public:
    Idk();
    Idk( int stuff );
    void incrementStuffOK( );
    void displayIdk( );
private:
    int stuff;
};  // don't forget the ;



int main()
{
    Idk myThing( 42 );
    myThing.displayIdk( );

    myThing.incrementStuffOK( );
    cout << "should have a higher number now..." << endl;
    myThing.displayIdk( );

    return 0;
}


Idk::Idk()
{
    Idk( 0 );
    return;
}


Idk::Idk( int stuff )
{
    this->stuff = stuff;
    return;
}

void Idk::displayIdk( )
{
    cout << "IDK: { stuff: " << this->stuff << " }" << endl;
}


void Idk::incrementStuffOK( )
{
    this->stuff++;
    return;
}


