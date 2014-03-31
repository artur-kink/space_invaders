#ifndef _PARTICLE_
#define _PARTICLE_

#include "draw.hpp"
#include "timer.h"
#include <stdlib.h>
#include <math.h>

class particle{
public:
    float x, y;
    float xVelocity, yVelocity;

    float rotation;
    float rotationVelocity;

    float r, g;

    Timer lifeTimer;

    bool destroy;

    particle(float x, float y);

    void update();
    void draw();
};

#endif