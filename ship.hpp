#ifndef _SHIP_
#define _SHIP_

#include "draw.hpp"
#include "bullet.hpp"

class ship{
public:
    float x;
    float y;

    float w;
    float h;

    virtual void draw() = 0;
};

#endif