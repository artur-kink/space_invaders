#ifndef _PARTICLE_
#define _PARTICLE_

#include "draw.hpp"
#include "timer.h"
#include <stdlib.h>
#include <math.h>

//Basic cube particle.
class particle{
public:
    //Position.
    float x, y, z;

    //Movement velocity.
    float xVelocity, yVelocity, zVelocity;

    //Particle rotation.
    float rotation;
    //Rotation velocity
    float rotationVelocity;

    //Red/Green color.
    float r, g;

    //Timer for life expectancy.
    Timer lifeTimer;

    //Should particle be destroyed?
    bool destroy;

    particle(float x, float y);

    void update();
    void draw();
};

#endif