#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;




// How far did the object fall in meters?
// 4
// The object fell for 0.90 seconds.
int main() {
    // do stuff here.
    // get the falling time of an object
    // given some height
    double height;
    cout << "How far did the object fall in meters?" << endl;
    cin >> height;

    // cout << "You have given height: " << height << endl;

    // calculate how long it takes for the object to fall
    // `height` meters
    double time;
    // time = squareRoot ( (2 * height) / 9.8 )
    // #include <cmath>
    // sqrt(number);
    time = sqrt((2*height)/9.8 );
    // cout << "time: " << time << endl;

    cout << "The object fell for " << fixed << setprecision(2) << time << " seconds." << endl;
}




// #include <iostream>
// using namespace std;

// int main(){
//     // declare all the variable
//     double fahrenheit, celsius;

//     // prompt the user & get their input
//     cout << "What is the temperature in Fahrenheit?" << endl; // EDIT THIS LINE TO PROMPT USER
//     cin >> fahrenheit;

//     // temperature calculation
//     celsius = (fahrenheit - 32.0) * (5.0/9.0); // EDIT THIS LINE TO CALCULATE TEMPERATURE
//     // hint: use (5.0/9.0) instead of (5/9)

//     cout << "The temperature is " << celsius << " degree Celsius." << endl;
//     return 0;
// }


// #include<iostream>
// using namespace std;

// int main() {
//     cout << "Hello, World!" << endl;
// }