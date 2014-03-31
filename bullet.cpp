#include "bullet.hpp"
bullet::bullet(float x, float y, float d){
    this->x = x;
    this->y = y;
    dir = d;

    destroy = false;
}

void bullet::update(){
    y+= dir*0.5f;
    if(y > 30 || y < -30)
        destroy = true;
}

void bullet::draw(){
    glPushMatrix();
        glTranslatef(x, y, 0);
        glColor3f(1.0f, 0.0f, 0.0f);
        draw::sphere(0.3f);
    glPopMatrix();
}