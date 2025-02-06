#include<iostream>  // cout, cin
#include<cmath>     // sqrt
#include<iomanip>   // setprecision
using namespace std;

// How far did the object fall in meters?
// 4
// The object fell for 0.90 seconds.
int main() {
    double heightInMeters, time;
    cout << "How far did the object fall in meters?" << endl;
    cin >> heightInMeters;
    // not always 0.90
    // instead its time = square root of { 2 * height / 9.8 }
    time = sqrt(2 * heightInMeters / 9.8);
    // CLOSE but not the right precision. Need 2 things after `.`
    // cout << "The object fell for " << time << " seconds." << endl;
    cout << "The object fell for " << fixed << setprecision(2) << time << " seconds." << endl;
}




// #include <iostream>
// using namespace std;


// // What is the temperature in Fahrenheit?
// // 32
// // The temperature is 0 degree Celsius.
// int main(){
//     // declare all the variable
//     double fahrenheit, celsius;

//     // prompt the user & get their input
//     cout << "What is the temperature in Fahrenheit?" << endl; // EDIT THIS LINE TO PROMPT USER
//     cin >> fahrenheit;

//     // temperature calculation
//     celsius = (fahrenheit - 32) * (5.0/9); // EDIT THIS LINE TO CALCULATE TEMPERATURE
//     // hint: use (5.0/9.0) instead of (5/9)

//     cout << "The temperature is " << celsius << " degree Celsius." << endl;
//     return 0;
// }