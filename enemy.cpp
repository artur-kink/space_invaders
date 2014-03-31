#include "enemy.hpp"

enemy::enemy(){
    dir = 1;
}

void enemy::update(){
    x += dir*0.5;
    if(dir > 0 && x > 37){
        dir = -1;
        y -= 3;
    }
    else if(dir < 0 && x < -37){
        dir = 1;
        y -= 3;
    }
}

void enemy::draw(){
    glPushMatrix();
        glTranslatef(x, y, 0);
        glColor3f(1.0f, 0, 0);
        draw::cube();
    glPopMatrix();
}