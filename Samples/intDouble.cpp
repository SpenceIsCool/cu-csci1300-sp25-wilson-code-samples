#include<iostream>
using namespace std;

int main() {
    cout << "\n\n\nLet's look at the math to convert 50 degrees farenheit to celcius:"
            << "\nthe EXPECTED ANSWER is 10"
            << "\n\t > all double no paren  : 50.0 - 32.0 * 5.0/9.0 BECOMES " << 50.0 - 32.0 * 5.0/9.0
            << "\n\t > all double with paren: (50.0 - 32.0) * 5.0/9.0 BECOMES " << (50.0 - 32.0) * 5.0/9.0
            << "\n\t > all int no paren     : 50 - 32 * 5/9 BECOMES " << 50 - 32 * 5/9
            << "\n\t > all int with paren   : (50 - 32) * 5/9 BECOMES " << (50 - 32) * 5/9
            << "\n\nplay with multiple parens:"
            << "\n\t > all double : (50.0 - 32.0) * (5.0/9.0) BECOMES " << (50.0 - 32.0) * (5.0/9.0)
            << "\n\t > most double: (50.0 - 32) * (5.0/9.0) BECOMES " << (50.0 - 32) * (5.0/9.0)
            << "\n\t > 5 int      : (50.0 - 32) * (5/9.0) BECOMES " << (50.0 - 32) * (5/9.0)
            << "\n\t > 9 int      : (50.0 - 32) * (5.0/9) BECOMES " << (50.0 - 32) * (5.0/9)
            << "\n\t > 5 and 9 int: (50.0 - 32) * (5/9) BECOMES " << (50.0 - 32) * (5/9)
            << "\n\n\n" << endl;
}
