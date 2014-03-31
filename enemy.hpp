#ifndef _ENEMY_
#define _ENEMY_

#include "ship.hpp"

class enemy:public ship{
public:

    float dir;

    enemy();

    void update();
    virtual void draw();
};

#endif