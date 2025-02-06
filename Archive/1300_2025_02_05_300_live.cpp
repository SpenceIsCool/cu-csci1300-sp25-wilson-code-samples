#include<iostream>
using namespace std;


// can we make this before
// areaGlobal is a "global" variable
// You can do it...
// I recommend avoiding it for now.
double areaGlobal;


// // I need a function to calculate the area of room
// // given some width and some length, find the area
// // double length - is a paremeter of my function
// // double width - is a paremeter of my function
// // double - the first word says what we are returning.
// double calculateRoomArea(double length, double width){
//     double area;
//     // If length or width is non-positive, -1 is returned.
//     // what is non-positive? 
//     //  negative numbers
//     //  zero is also non-positive
//     if ( length <= 0 )
//     {
//         if ( width <= 0 )
//         {
//             return -1;
//         }
//     }
//     area = length * width; 
//     return area;
// }


// -40 and 2 should get -1, but got -80
/**
 * calculateRoomArea
 * given a length and a width
 * find the area
 */ 
double calculateRoomArea(double length, double width){
    // double area;
    // bool invalid;
    // invalid = false;
    // if ( length <= 0 || width <= 0 )
    // {
    //     invalid = true;
    // }

    // if ( ! invalid )
    // {
    //     area = length * width; 
    //     return area;
    // }
    // else
    // {
    //     return -1;
    // }  

    if ( length <= 0 || width <= 0 ) 
    {
        return -1;
    }
    return width * length;
}


int main()
{
    // int x = x;
    // cout << x << endl;
    
    double areaFound, areaExpected;
    // length will be 2
    // width will be 6
    areaFound = calculateRoomArea( 2, 6 );
    areaExpected = 12;
    cout << "   Found area: " << areaFound << endl;
    cout << "Expected area: " << areaExpected << endl;

    // length will be 15
    // width will be 2
    areaFound = calculateRoomArea( 15, 2 );
    areaExpected = 30;
    cout << "   Found area: " << areaFound << endl;
    cout << "Expected area: " << areaExpected << endl;


    // length will be -40
    // width will be 2
    areaFound = calculateRoomArea( -40, 2 );
    areaExpected = -1;
    cout << "   Found area: " << areaFound << endl;
    cout << "Expected area: " << areaExpected << endl;
    return 0;
}