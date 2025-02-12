/**
 * loops.cpp
 * @author Spencer Wilson 
 * @date Febuary 10, 2025
 *
 * A file to help us tinker with loops
 * It has an excess of functions to play with
 * It shows us everything that we have learned so far this semseter
 * It might be intimdating at first and that's okay
 * Please focus on the planned notes below
 *
 * PLAN FOR LECTURE Feb 12:
 *  - Q&A on doublingPenny
 *  - COLLAB on productOfNumbers (try in advance if you can)
 *  - ADDED LATE: we should show string iterations...
 *  - SHOW forLoops
 *  - CHANGE doublingPenny to use a forLoop
 *  - Q&A forLoops
 *  - Q&A on countChar
 */
#include<iostream>  // cout, cin, endl
#include<cassert>  // assert
using namespace std;


// A global variable. be very carefuly using these
// typically avoid them
// does not HAVE to be all UPPER-CASE
// just nice sometimes
bool DEBUG = false;


// NOTE how we can quickly observe what functions are available.
// some setup stuff
// VSCode has Hot-keys to "go to the definition" of a function
bool setDebug();
bool handleMenu( );
// some fun old stuff
void boolPrecedence( );
void division( );
// the new stuff
void doublingPenny( );
void productOfNumbers();
void forLoops( );
int countChar( string s, char c );
void testCountChar( );


/**
 * main
 * the driver of all of the work to be done
 * it will call the funcitions above for us as needed
 */
int main ( )
{
    bool keepGoing;


    keepGoing = true;
    // a do-while loop is great for menu's:
    // OBSERVE: how it's slightly less work
    // THESE ARE ABOUT THE SAME::
    //
    //    thing;
    //    while ( quesiton ) { 
    //       thing;
    //    }
    //
    keepGoing = setDebug();
    while ( keepGoing )
    {
        keepGoing = setDebug();
    }

    keepGoing = true;
    //    do {
    //        thing
    //    } while ( question ); 
    do
    {
        keepGoing = handleMenu();
    } while ( keepGoing );  // don't forget the ;

    cout << "\n\n\nThank you for stoping by.\n\n\n" << endl;

}


/**
 * setDebug
 * Used to set the global `DEBUG` varaible
 * we often avoid globals, but they can be useful as shown
 * with this `DEBUG` variable
 * This particular solution is more complicated then it needs to be
 *
 * @returns false if the value has been set validly
 */
bool setDebug( )
{
    int userInput;

    cout << "Would you like to set debug on?"
         << "\n\t1. yes"
         << "\n\t2. no"
         << endl;
    cin >> userInput;

    if ( userInput == 1 )
    {
        DEBUG = true;
    }
    else if ( userInput == 2 )
    {
        DEBUG = false;
    }
    else
    {
        // the user put in something invalid!
        return true;
    }
    return false;
}


/**
 * handleMenu
 * prompt the user a variety of options
 * based on their response take the appropraite action
 *
 * @returns: false if the user does not want to continue, else true
 */
bool handleMenu( )
{
    int selection;

    // `\n` means new line. It's a lot like `endl`
    //         You can google the difference but it's not too important right now.
    //         For homeworks, use endl for autograding reasons
    // `\t` means format a `tab` for me
    // yes, you can multi-line cout like this::
    cout << "\n\n\n"
         << "What shall we do next?"
         << "\n\t0. I'm done."
         << "\n\t1. I've changed my mind about debug."
         << "\n\t2. boolean precedence"
         << "\n\t3. division"
         << "\n\t4. doubling a penny"
         << "\n\t5. product of many numbers"
         << "\n\t6. for loops"
         << "\n\t7. counting characters"
         << endl;
    cin >> selection;
    switch ( selection )
    {
        case 0:
            // return from handleMenu, ignore the rest of the switch
            return false;
        case 1:
            DEBUG = !DEBUG;
            // ()?: is called a ternary. you can google it or not.
            cout << "Changing debug to: " << ((DEBUG)?"ON":"OFF") << endl;
            // break out of this switch
            break;
        case 2:
            boolPrecedence();
            // break out of this switch
            break;
        case 3:
            division();
            // break out of this switch
            break;
        case 4:
            doublingPenny();
            // break out of this switch
            break;
        case 5:
            productOfNumbers();
            // break out of this switch
            break;
        case 6:
            forLoops();
            // break out of this switch
            break;
        case 7:
            testCountChar();
            // break out of this switch
            break;
        default:
            cout << "Please enter a valid number" << endl;
    }
    // break takes us to here...
    return true;
}


/**
 * doublingPenny
 * find the value of doubling a penny 31 times
 * A fun thing about compound interest. Would you rather have
 * $5Million today or a penny that doubles in value every
 * day for 31 days?
 */
void doublingPenny( )
{
    // SET: value = 0.01
    double value = 0.01;
    
    // SET days remaining = 31
    // REPEATE while days remaining
    // Decrease days remaining
    for ( int days = 31 ; days > 0 ; days-- ) {
        if ( DEBUG ) cout << "The value is " << value << " with " << days << " remaining to compound interest." << endl;
        // Double the value
        value *= 2;
        
    }

    cout << "After 31 days the value of the magic penny is: " << value << endl;
}
// void doublingPenny( )
// {
//     // SET: value = 0.01
//     double value = 0.01;
//     // SET days remaining = 31
//     int days = 31;

//     // REPEATE while days remaining
//     while ( days > 0 ) {
//         if ( DEBUG ) cout << "The value is " << value << " with " << days << " remaining to compound interest." << endl;
//         // Double the value
//         value *= 2;
//         // Decrease days remaining
//         days--;
//     }

//     cout << "After 31 days the value of the magic penny is: " << value << endl;
// }




/**
 * boolPrecedence
 * demonstrate that && has higher precedence than || in C++
 *  let 0 be false
 *  let 1 be true
 *  observe that  A && B || C has a different value from A && (B || C)
 *  A B C __ A && B __ A && B || C __ B || C __ A && (B || C)
 *  0 0 0 __ 0      __ 0           __ 0      __ 0
 *  0 0 1 __ 0      __ 1           __ 1      __ 0  << DIFFERENT!
 *  0 1 0 __ 0      __ 0           __ 1      __ 0
 *  0 1 1 __ 0      __ 1           __ 1      __ 0
 *  1 0 0 __ 0      __ 0           __ 0      __ 0
 *  1 0 1 __ 0      __ 1           __ 1      __ 1
 *  1 1 0 __ 1      __ 1           __ 1      __ 1
 *  1 1 1 __ 1      __ 1           __ 1      __ 1
 */
void boolPrecedence()
{
    bool b0, b1, b2;
    b0 = (false && false) || true;
    b1 = false && (false || true);
    // To really get this to work...
    // Build without -Werror
    // and change out which of these definitions of b2 are used...
    // b2 = false && false || true;
    b2 = (false && false) || true;

    string s0, s1, s2;
    if (b0)
    {
        s0 = "TRUE";
    }
    else
    {
        s0 = "FALSE";
    }

    // "ternary operation" like the above if/else but tighter
    s1 = ( b1 ) ? "TRUE" : "FALSE";
    s2 = ( b2 ) ? "TRUE" : "FALSE";

    cout << "(false && false) || true EVALUATES TO: " << s0 << endl;
    cout << "false && (false || true) EVALUATES TO: " << s1 << endl;
    cout << "false && false || true   EVALUATES TO: " << s2 << endl;
    cout << "NOTE: false && false || true   is the same as (false && false) || true\n"
         << "      but it is different from false && (false || true)\n"
         << "      so && must have the higher precedence.\n"
         << "      think of it like (1+2)*3 vs 1+(2*3)"
         << endl; 
    return;
}


/**
 * division
 * given two integer values
 * show the division and remainder
 */
void division ( )
{
    int x, y;
    cout << "I can haz two numbers?" << endl;
    cin >> x >> y;

    cout << x << " divided by " << y << " = " << x/y << " plus a remainder of " <<  x%y << " over " << y << endl;
    cout << x << " / " << y << " = " << x/y << endl;
    cout << x << " % " << y << " = " << x%y << endl;
}

/**
 * asked after class, what is my favorite kind of loop?
 * I like to do the following
 * Note that each line does exactly one thing
 * the while condition `keepGoing` just feels easier to read to me
 */
int idk()
{
    bool keepGoing = true;
    int i = 0;
    while ( keepGoing )
    {
        cout << "Hello" << endl;
        i++;
        if ( i > 5 )
        {
            keepGoing = false;
        }
    }
    return 1;
}

/**
 * productOfNumbers
 * ask the user how many numbers they want us to find the product of
 * then find that product
 */
void productOfNumbers()
{
    // BEGIN
    // Ask the user how many numbers they care to get a product of
    int count;
    cout << "how many numbers will you give me?" << endl;
    cin >> count;
    // initialize some partial product tracker
    // int productSoFar = 0;  // 0 will cause us to always get 0
    // the identity of multiplication is 1
    int productSoFar = 1;
    // REPEATE while more numbers need to be gotten
    while ( count > 0 )
    {
        // get the value 
        int thisNumber;
        cout << "give me one number please:" << endl;
        // cin lets me have space separated inputs
        // so I can technically have them all at once
        cin >> thisNumber;
        // update the partial product tracker
        // productSoFar * thisNumber; // not quite enough
        // productSoFar = productSoFar * thisNumber; // good enough, but lets make fancy syntax
        productSoFar *= thisNumber;
            // CHALLENGE: what if the product could be known early?
        // OOPS: bad comments, don't forget to decrement count
        count--;
    }
    // SHOW the value of the product
    cout << "I found that product you asked for: " << productSoFar << endl;
    // END

    // ADDED LATE: we should show string iterations...
    
    return;
}


/**
 * forLoops
 * a place to play with forloops
 * nothing overly planned yet
 */
void forLoops()
{
    cout << "\n\n\n"
         << "for ( int i = 0 ; i < 10 ; i++ ) <print i>" << endl;
    for ( int i = 0 ; i < 10 ; i++ )
    {
        cout << "\t" << i << endl;
    }

    cout << "\n\n\n"
         << "for ( int i = 10 ; i > 0 ; i-- ) <print i>" << endl;
    for ( int i = 10 ; i > 0 ; i-- )
    {
        cout << "\t" << i << endl;
    }

    cout << "\n\n\n"
         << "for ( int j = 0 ; j < 5 ; j++ )"
         << "\n     <print j>"
         << "\n     for ( int k = 10 ; k > j ; k-- ) <print k comma separated in same line>" << endl;
    for ( int j = 0 ; j < 5 ; j++ )
    {
        cout << j << ": ";
        for ( int k = 10; k > j ; k-- )
        {
            cout << k << ", ";
        }
        cout << endl;
    }
    return;
}


/**
 * countChar
 * count the number of times some character appears in some string
 * * @param s: the string of interest
 * @param c: the character of interst
 * @returns: the number of time c appears in s
 */
int countChar( string s, char c )
{
    // BEGIN
    // have some kind of counter set to 0
    int count = 0;
    // REPEATE: until the full string is read
    for ( int i = 0 ; i < s.length() ; i++ )
    {
        // get the left-most unread character
        char leftMost = s[i];
        // if that character is the same as `c`
        if ( leftMost == c )
        {
            // then increment the counter
            count++;
        }
    }
    // END
    return count;
}


/**
 * testCountChar
 * automates testing of the countChar function
 */
void testCountChar( )
{
    assert( countChar( "" , 'S' ) == 0 );
    assert( countChar( "snakes" , 'S' ) == 0 );
    assert( countChar( "SNAKES" , 'S' ) == 2 );
    assert( countChar( "SNAKES" , 'A' ) == 1 );
    cout << "\n\n\n$$$$$$$$$$$$$$$\n\tALL TESTS PASSED\n$$$$$$$$$$$$$$$\n\n\n" << endl;
    return;
}


