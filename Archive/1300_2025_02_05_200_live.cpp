#include<iostream>
using namespace std;


// DECLARE all funtions
// don't forget the semi-colon.
double calculateRoomArea(double length, double width);


// DEFINE main
int main()
{
    // check that area of 2 x 3 is 6
    double area;
    // length is 2, width is 3
    area = calculateRoomArea( 2, 3 );
    cout << "found area: " << area << endl;
    cout << "I'm expecting 6" << endl;

    // length is -2, width is 3
    area = calculateRoomArea( -2, 3 );
    cout << "found area: " << area << endl;
    cout << "I'm expecting -1" << endl;


    cout << "Hello, World!" << endl;
    // things are bad if we return something that isn't 0
    return EXIT_FAILURE;
    return 1;
    // 0 means all is well
    return 0;
}

// DEFINE all funtions other than main
/** 
 * calculateRoomArea
 * given a length and a width figure out the area
 */
double calculateRoomArea(double length, double width)
{
    if ( length <= 0  || width <= 0 )
    {
        return -1;
    }
    return length * width;
}

// // below are some original versions of the code from lecture
// // 1. highlight 
// // 2. ctrl + / (to comment or uncomment all of it)
// // I want to write a function to calculate the area of a room
// // I am given a length (as a double)
// // and a width (as a double)
// double calculateRoomArea(double length, double width)
// {
//     // // if the length or width is non-positive (<= 0), return -1
//     // if ( length <= 0 )
//     // {
//     //     if ( width <= 0 )
//     //     {
//     //         return -1;
//     //     }
//     // }
//     if ( length <= 0  || width <= 0 )
//     {
//         // what happens when we hit a `return`
//         // much like how `break` ends a `switch`
//         // `return` will end any function for us
//         return -1;
//         cout << "Hey this is super silly unreachable code" << endl;
//     }

//     // do we need to write else here?
//     return length * width;
// }
