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
		// scale the enemy size
		glScalef(0.2, 0.2, 1);
		
		// left side
		glPushMatrix();
			glTranslatef(x-10, y-2, 0);
			glScalef(1, 3, 1);
			glColor3f(1.0f, 0, 0);
			draw::cube();
		glPopMatrix();
		glPushMatrix();
			glTranslatef(x-8, y+1, 0);
			glScalef(1, 2, 1);
			glColor3f(1.0f, 0, 0);
			draw::cube();
		glPopMatrix();
		glPushMatrix();
			glTranslatef(x-6, y, 0);
			glScalef(1, 5, 1);
			glColor3f(1.0f, 0, 0);
			draw::cube();
		glPopMatrix();
		glPushMatrix();
			glTranslatef(x-6, y+8, 0);
			glColor3f(1.0f, 0, 0);
			draw::cube();
		glPopMatrix();
		glPushMatrix();
			glTranslatef(x-4, y, 0);
			glColor3f(1.0f, 0, 0);
			draw::cube();
		glPopMatrix();
		glPushMatrix();
			glTranslatef(x-4, y+5, 0);
			glScalef(1, 2, 1);
			glColor3f(1.0f, 0, 0);
			draw::cube();
		glPopMatrix();
		// body
		glPushMatrix();
			glTranslatef(x, y+1, 0);
			glScalef(3, 4, 1);
			glColor3f(1.0f, 0, 0);
			draw::cube();
		glPopMatrix();
		
		// right side
		glPushMatrix();
			glTranslatef(x+10, y-2, 0);
			glScalef(1, 3, 1);
			glColor3f(1.0f, 0, 0);
			draw::cube();
		glPopMatrix();
		glPushMatrix();
			glTranslatef(x+8, y+1, 0);
			glScalef(1, 2, 1);
			glColor3f(1.0f, 0, 0);
			draw::cube();
		glPopMatrix();
		glPushMatrix();
			glTranslatef(x+6, y, 0);
			glScalef(1, 5, 1);
			glColor3f(1.0f, 0, 0);
			draw::cube();
		glPopMatrix();
		glPushMatrix();
			glTranslatef(x+6, y+8, 0);
			glColor3f(1.0f, 0, 0);
			draw::cube();
		glPopMatrix();
		glPushMatrix();
			glTranslatef(x+4, y, 0);
			glColor3f(1.0f, 0, 0);
			draw::cube();
		glPopMatrix();
		glPushMatrix();
			glTranslatef(x+4, y+5, 0);
			glScalef(1, 2, 1);
			glColor3f(1.0f, 0, 0);
			draw::cube();
		glPopMatrix();
		
		glPushMatrix();
			glTranslatef(x-3, y-6, 0);
			glScalef(2, 1, 1);
			glColor3f(1.0f, 0, 0);
			draw::cube();
		glPopMatrix();
		glPushMatrix();
			glTranslatef(x+3, y-6, 0);
			glScalef(2, 1, 1);
			glColor3f(1.0f, 0, 0);
			draw::cube();
		glPopMatrix();
	glPopMatrix();
}
