#include "bullet.hpp"
bullet::bullet(float x, float y, float d){
    this->x = x;
    this->y = y;
    dir = d;

    destroy = false;
}

void bullet::update(){
    //Update position
    y+= dir*0.5f;

    //If bullet off screen mark as destroy.
    if(y > 28 || y < -28)
        destroy = true;
}

void bullet::draw(){
    glPushMatrix();
        glTranslatef(x, y, 0);
        //Set red if falling down(enemy bullet)
        if(dir < 0)
            glColor3f(1.0f, 0.0f, 0.0f);
        else
            glColor3f(1.0f, 1.0f, 1.0f);
        draw::sphere(0.4f);
    glPopMatrix();
}