#include "particle.hpp"

particle::particle(float x, float y){
    this->x = x;
    this->y = y;

    xVelocity = (float)((rand() % 10) - 5)/10.0;
    yVelocity = (float)((rand() % 10) - 5)/10.0;
    rotationVelocity = (float)(rand() % 10)/10.0;

    r = (float)(rand() % 10) / 10.0;
    g = (float)(rand() % 10) / 10.0;

    //Ensure yellow-red spectrum.
    if(g >= r){
        r = g + 0.1f;
    }

    destroy = false;
    lifeTimer.reset();
}

void particle::update(){
    x += xVelocity;
    y += yVelocity;
    rotation += rotationVelocity;
    if(lifeTimer.elapsed() > 1){
        destroy = true;
    }
}

void particle::draw(){
    glPushMatrix();
        glColor4f(r*(1 - lifeTimer.elapsed()), g*(1 - lifeTimer.elapsed()), 0, 0.0);
        glTranslatef(x, y, 0);
        glScalef(0.2, 0.2, 0.2);
        glRotatef(rotation, rotation, rotation, 0);
        draw::cube();
    glPopMatrix();
}