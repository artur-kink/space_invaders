#ifndef _ENEMY_
#define _ENEMY_

#include "ship.hpp"
#include "timer.h"

class enemy:public ship{
public:

	Timer animationTimer;
	bool frame;

    float dir;

    enemy();

    void update();
    virtual void draw();
};

#endif
