#include "particle.hpp"

particle::particle(float x, float y){
    this->x = x;
    this->y = y;
    z = 0;

    //Set random movement velocities.
    xVelocity = (float)((rand() % 10) - 5)/50.0;
    yVelocity = (float)((rand() % 10) - 5)/50.0;
    zVelocity = (float)((rand() % 10) - 5)/30.0;

    //Set random rotation velocity.
    rotationVelocity = (float)(rand() % 10)/5.0;
    rotationVelocity *= 3.0f;

    //Set random red/green color values.
    r = (float)(rand() % 10) / 10.0;
    g = (float)(rand() % 10) / 10.0;

    //Ensure yellow-red spectrum.
    if(g >= r){
        r = g + 0.2f;
    }

    destroy = false;
    lifeTimer.reset();
}

void particle::update(){
    //Update position and rotation.
    x += xVelocity;
    y += yVelocity;
    z += zVelocity;
    rotation += rotationVelocity;

    //If particle has been alive for over 2 seconds mark as destroy.
    if(lifeTimer.elapsed() > 2){
        destroy = true;
    }
}

void particle::draw(){
    glPushMatrix();
        //Set color and fade to black based on lifetime.
        glColor3f(r*(2 - lifeTimer.elapsed()), g*(2 - lifeTimer.elapsed()), 0);
        glTranslatef(x, y, z);
        glScalef(0.2, 0.2, 0.2);
        glRotatef(rotation, rotation, rotation, 0);
        draw::cube();
    glPopMatrix();
}