// Delta.cpp
#include "Delta.h"

Delta::Delta()
{
    c = Charlie();
}

int Delta::doubleX()
{
    c.setX( c.getX() * 2 );
    return c.getX();
}

