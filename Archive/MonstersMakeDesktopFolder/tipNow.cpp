#include<iostream>
using namespace std;

int main() {
    int _my_special_var6; 
    double total;
    double tipPercent;
    double tipValue;

    total = 10.77;
    tipPercent = 0.25;
    tipValue = total * tipPercent;
    cout << "Your tip value is: " << tipValue << endl;
    cout << "Your total after tip value is: ???" << endl;
}


// #include<iostream>
// using namespace std;

// int main() {
//     // I'd like to get the total of a bill
//     // is total a integer, or a real number (we have change)
//     double total;
//     // and I'd like to tip 25%
//     // is tip an integer or a real number (a percentage)
//     double tip;

//     total = 10.77;
//     tip = 0.25;
//     cout << "Your tip value is: " << total * tip << endl;
//     cout << "Your total after tip value is: ???" << endl;
// }