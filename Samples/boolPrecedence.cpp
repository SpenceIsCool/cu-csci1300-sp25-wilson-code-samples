// DO NOT compile with -Werror
#include<iostream>
using namespace std;


// // && has heigher precedence than || in C++
// // let 0 be false
// // let 1 be true
// // observe that  A && B || C has a different value from A && (B || C)
// A B C __ A && B __ A && B || C __ B || C __ A && (B || C)
// 0 0 0 __ 0      __ 0           __ 0      __ 0
// 0 0 1 __ 0      __ 1           __ 1      __ 0  << DIFFERENT!
// 0 1 0 __ 0      __ 0           __ 1      __ 0
// 0 1 1 __ 0      __ 1           __ 1      __ 0
// 1 0 0 __ 0      __ 0           __ 0      __ 0
// 1 0 1 __ 0      __ 1           __ 1      __ 1
// 1 1 0 __ 1      __ 1           __ 1      __ 1
// 1 1 1 __ 1      __ 1           __ 1      __ 1
int main()
{
    bool b0, b1, b2;
    b0 = (false && false) || true;
    b1 = false && (false || true);
    b2 = false && false || true;

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
}
