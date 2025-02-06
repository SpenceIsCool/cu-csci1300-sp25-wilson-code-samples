#include <iostream>
using namespace std;

int main() {
    double cheesePizzaAndSoda = 10.77;
    double tipPercentage = 0.22;
    double tipAmount = cheesePizzaAndSoda * tipPercentage;
    double totalAmount = cheesePizzaAndSoda + tipAmount;
    cout << "The tip amount is: " << tipAmount 
            << "\nAnd the total is: " << totalAmount << endl;
}
