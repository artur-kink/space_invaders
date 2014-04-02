#include "player.hpp"

player::player(){
    y = -25;
    x = 0;

    w = 2.5;
    h = 2;
}

//Draw player ship.
void player::draw(){
    glPushMatrix();
		glTranslatef(x, y + 14 / 5.0, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(1.0f, 1.0f, 1.0f);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x, y + 10 / 5.0, 0);
		glScalef(0.6, 0.6, 0.6);
		glColor3f(1.0f, 1.0f, 1.0f);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x, y + 6 / 5.0, 0);
		glScalef(2.2, 0.2, 0.6);
		glColor3f(1.0f, 1.0f, 1.0f);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x, y, 0);
		glScalef(2.6, 1.0, 0.6);
		glColor3f(1.0f, 1.0f, 1.0f);
		draw::cube();
	glPopMatrix();
}
