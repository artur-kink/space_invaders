#include "particle.hpp"

particle::particle(float x, float y){
    this->x = x;
    this->y = y;
    z = 0;

    xVelocity = (float)((rand() % 10) - 5)/50.0;
    yVelocity = (float)((rand() % 10) - 5)/50.0;
    zVelocity = (float)((rand() % 10) - 5)/50.0;
    
    rotationVelocity = (float)(rand() % 10)/5.0;
    rotationVelocity *= 3.0f;

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
    x += xVelocity;
    y += yVelocity;
    z += zVelocity;
    rotation += rotationVelocity;
    if(lifeTimer.elapsed() > 2){
        destroy = true;
    }
}

void particle::draw(){
    glPushMatrix();
        glColor3f(r*(2 - lifeTimer.elapsed()), g*(2 - lifeTimer.elapsed()), 0);
        glTranslatef(x, y, z);
        glScalef(0.2, 0.2, 0.2);
        glRotatef(rotation, rotation, rotation, 0);
        draw::cube();
    glPopMatrix();
}