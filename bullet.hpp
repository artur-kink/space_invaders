#ifndef _BULLET_
#define _BULLET_

#include "draw.hpp"

//Bullet
class bullet{
public:
    //Bullet Position.
    float x, y;

    //Vertical direction.
    float dir;

    //Should bullet be destroyed.
    bool destroy;
    
    bullet(float x, float y, float d);
    void update();
    void draw();
};

#endif