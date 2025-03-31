// DeltaWrong.cpp
// build: 
// g++ -o runMe.out -Wall -Werror -Wpedantic -Wsign-compare Charlie.cpp DeltaWrong.cpp main.cpp
#include "Delta.h"

Delta::Delta()
{
    c = Charlie();
}

int Delta::doubleX()
{
    int x = c.getX( );
    x *= 2;
    return x;
}

