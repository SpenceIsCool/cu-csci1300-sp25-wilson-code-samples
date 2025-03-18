#include<iostream>
using namespace std;


struct Address {
    string street;
    char state1;
    char state2;
    unsigned int zip;
};
struct Shop {
    string name;
    Address address;
};


int main() 
{
    Address a0 = { "1755 29th St # 1096", 'C', 'O', 80301 };
    Shop s0 = { "Carhartt", a0 };

    Shop s1 = { "REI", { "1789 28th St", 'C', 'O', 80301 } };
    return 0;
}

