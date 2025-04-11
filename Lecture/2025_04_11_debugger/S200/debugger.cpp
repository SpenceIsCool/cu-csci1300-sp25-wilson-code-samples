/**
 * debugger.cpp
 * 
 * follow instructions in appendix D debugger: https://cu-csci-1300-intro-programming.github.io/spring-2025-web/jekyll/update/2025/01/07/Appendix-D.html#mac-installation
 */
#include<iostream>
using namespace std;


int main( )
{
    
    int x = 5;
    int y = 2;

    double sum = 0;
    for ( unsigned int i = 0 ; i < 20 ; i++ )
    {
        double thing = x / y;
        sum += thing;
    }
    cout << "sum found: " << sum << endl;  // expect 50

    return 0;
}

