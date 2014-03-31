#include "player.hpp"

player::player(){
    y = -25;
    x = 0;
}

void player::draw(){
    glPushMatrix();
        glTranslatef(x, y, 0);
        glColor3f(1.0f, 1.0f, 1.0f);
        draw::cube();
    glPopMatrix();
}