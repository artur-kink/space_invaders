#ifndef _BULLET_
#define _BULLET_

#include "draw.hpp"

class bullet{
public:
    float x, y;
    float dir;
    bool destroy;
    
    bullet(float x, float y, float d);
    void update();
    void draw();
};

#endif