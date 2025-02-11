#include<iostream>
using namespace std;


void helloWorldOnce();
void helloWorldFiveTimes();
void helloWorldFiveTimesWhile();
void helloWorldNTimesWhile( int n );
void helloWorldNTimesFor( int n );
void condition();
void foo();
void bar();
void baz();
void sampleUpDown();
void sampleForWhile();


int main( )
{
    cout << "\n\n\nhelloWorldOnce:" << endl;
    helloWorldOnce();
    cout << "\n\n\nhelloWorldFiveTimes:" << endl;
    helloWorldFiveTimes();
    cout << "\n\n\nhelloWorldFiveTimesWhile:" << endl;
    helloWorldFiveTimesWhile();
    cout << "\n\n\nhelloWorldNTimesWhile( 2 ):" << endl;
    helloWorldNTimesWhile( 2 );
    cout << "\n\n\nhelloWorldNTimesFor( 6 ):" << endl;
    helloWorldNTimesFor( 6 );
    cout << "\n\n\ncondition:" << endl;
    condition();
    cout << "\n\n\nfoo: runs forever, don't run it!" << endl;
    // foo();
    cout << "\n\n\nbar:" << endl;
    bar();
    cout << "\n\n\nbaz:" << endl;
    baz();
    cout << "\n\n\nsampleUpDown:" << endl;
    sampleUpDown();
    cout << "\n\n\nsampleForWhile:" << endl;
    sampleForWhile();
}

void helloWorldOnce()
{
    cout << "Hello, World!" << endl;
}

void helloWorldFiveTimes()
{
    cout << "Hello, World!" << endl;
    cout << "Hello, World!" << endl;
    cout << "Hello, World!" << endl;
    cout << "Hello, World!" << endl;
    cout << "Hello, World!" << endl;
}



void helloWorldFiveTimesWhile()
{
    int remaining = 5;
    while ( remaining > 0 )
    {
        cout << "Hello, World!" << endl;
        // DON'T FORGET ME!
        remaining--;
    }
}


void helloWorldNTimesWhile( int n )
{
    int remaining = n;
    while ( remaining > 0 )
    {
        cout << "Hello, World!" << endl;
        // DON'T FORGET ME!
        remaining--;
    }
}


void helloWorldNTimesFor( int n )
{
    for ( int remaining = n ; remaining > 0 ; remaining-- )
    {
        cout << "Hello, World!" << endl;
    }
}





// How many times does this print?
// A. infinite
// B. once
// C. 5 times
// D. something else
void condition()
{
    int remaining = 5;
    if ( remaining > 0 )
    {
        cout << "Hello, World!" << endl;
    }
}

// How many times does this print?
// A. infinite
// B. once
// C. 5 times
// D. something else
void foo()
{
    int remaining = 5;
    while ( remaining > 0 )
    {
        cout << "Hello, World!" << endl;
    }
}

// How many times does this print?
// A. infinite
// B. once
// C. 5 times
// D. something else
void bar()
{
    int remaining = 5;
    while ( remaining > 0 )
    {
        cout << "Hello, World!" << endl;
        // DON'T FORGET ME!
        remaining--;
    }
}

// How many times does this print?
// A. infinite
// B. once
// C. 5 times
// D. something else
void baz()
{
    int complete = 0;
    while ( complete < 5 )
    {
        cout << "Hello, World!" << endl;
        // DON'T FORGET ME!
        complete++;
    }
}


void sampleUpDown()
{
    int i = 5;
    while ( i > 0 )
    {
        cout << "DOWN: Hello, World!" << endl;
        i--;
    }

    int j = 0;
    while ( j < 5 )
    {
        cout << "UP: Hello, World!" << endl;
        j++;
    }
}


void sampleForWhile()
{
    int i = 0;
    while ( i < 5 )
    {
        cout << "WHILE: Hello, World!" << endl;
        i++;
    }

    for ( int j = 0 ; j < 5 ; j++ )
    {
        cout << "FOR: Hello, World!" << endl;
    }
}

