#ifndef _SHIP_
#define _SHIP_

#include "draw.hpp"
#include "bullet.hpp"

class ship{
public:
    float x;
    float y;

    virtual void draw() = 0;
};

#endif