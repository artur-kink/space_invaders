#ifndef _SHIP_
#define _SHIP_

#include "draw.hpp"
#include "bullet.hpp"

//Base ship class
class ship{
public:
    //Position
    float x;
    float y;

    //Width and height
    float w;
    float h;

    virtual void draw() = 0;
};

#endif