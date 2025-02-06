#include<iostream>

int main() {
    double total;
    double tipPercentage;
    double tipTotal;

    std::cout << "How much is the total?" << std::endl;
    std::cin >> total;

    std::cout << "How much is the tip percentage?" << std::endl;
    std::cin >> tipPercentage;

    tipTotal = total * tipPercentage;
    std::cout << "You should tip " <<  tipTotal << " dollar value" << std::endl;
}



// #include<iostream>

// int main() {
//     // I want to develop a tool that helps me tip a server
//     // I need to know the total
//     double total;
//     // and I need to know the percent I want to tip
//     // double as I have factions
//     double tip;

//     std::cout << "How much is the total?" << std::endl;
//     // get input from the user and store to total
//     std::cin >> total;

//     std::cout << "How much is the tip percentage?" << std::endl;
//     std::cin >> tip;

//     // std::cout << "You should tip ??? dollar value" << std::endl;
//     std::cout << "You should tip " << total * tip << " dollar value" << std::endl;
// }