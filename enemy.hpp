#ifndef _ENEMY_
#define _ENEMY_

#include "ship.hpp"
#include "timer.h"
#include "color.hpp"

class enemy:public ship{
public:

	Timer animationTimer;
	bool frame;

    float dir;
    int type;

    //Enemy color.
    color c;

    enemy();
    enemy(float x, float y, int t);

    void update();
    virtual void draw();
};

#endif
