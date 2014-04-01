#include "enemy.hpp"

enemy::enemy(){
    dir = 1;
    c = magenta;
    type = 0;
    animationTimer.reset();
}

enemy::enemy(float x, float y, int t){
    this->x = x;
    this->y = y;
    type = t;

    dir = 1;
    c = magenta;
    animationTimer.reset();
}

void enemy::update(){
    x += dir*0.2;
    if(dir > 0 && x > 37){
        dir = -1;
        y -= 3;
    }
    else if(dir < 0 && x < -37){
        dir = 1;
        y -= 3;
    }
}

void enemy::drawEnemy0() {
	// left side
	glPushMatrix();
		glTranslatef(x - 10 / 5.0, y - 2 / 5.0, 0);
		glScalef(0.2, 0.6, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
		glPushMatrix();
		glTranslatef(x - 8 / 5.0, y + 1 / 5.0, 0);
		glScalef(0.2, 0.4, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 6 / 5.0, y, 0);
		glScalef(0.2, 1.0, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 6 / 5.0, y + 8 / 5.0, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 4 / 5.0, y - 1 / 5.0, 0);
		glScalef(0.2, 0.4, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 4 / 5.0, y + 5 / 5.0, 0);
		glScalef(0.2, 0.4, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	
	// body
	glPushMatrix();
		glTranslatef(x, y + 1 / 5.0, 0);
		glScalef(0.6, 0.8, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();

	// right side
	glPushMatrix();
		glTranslatef(x + 10 / 5.0, y - 2 / 5.0, 0);
		glScalef(0.2, 0.6, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 8 / 5.0, y + 1 / 5.0, 0);
		glScalef(0.2, 0.4, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 6 / 5.0, y, 0);
		glScalef(0.2, 1.0, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 6 / 5.0, y + 8 / 5.0, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 4 / 5.0, y - 1 / 5.0, 0);
		glScalef(0.2, 0.4, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 4 / 5.0, y + 5 / 5.0, 0);
		glScalef(0.2, 0.4, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(x - 3 / 5.0, y - 6 / 5.0, 0);
		glScalef(0.4, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 3 / 5.0, y - 6 / 5.0, 0);
		glScalef(0.4, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();

	// Eyes
	glPushMatrix();
		glTranslatef(x - 4 / 5.0, y + 2 / 5.0, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(0, 0, 0);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 4 / 5.0, y + 2 / 5.0, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(0, 0, 0);
		draw::cube();
	glPopMatrix();
}

void enemy::drawEnemy0B() {
	// Left side
	glPushMatrix();
		glTranslatef(x - 10 / 5.0, y + 3 / 5.0, 0);
		glScalef(0.2, 0.8, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 8 / 5.0, y, 0);
		glScalef(0.2, 0.6, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 8 / 5.0, y - 6 / 5.0, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 6 / 5.0, y, 0);
		glScalef(0.2, 1.0, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 6 / 5.0, y + 8 / 5.0, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 4 / 5.0, y - 1 / 5.0, 0);
		glScalef(0.2, 0.4, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 4 / 5.0, y + 5 / 5.0, 0);
		glScalef(0.2, 0.4, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	
	// body
	glPushMatrix();
		glTranslatef(x, y + 1 / 5.0, 0);
		glScalef(0.6, 0.8, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	
	// Right side
	glPushMatrix();
		glTranslatef(x + 10 / 5.0, y + 3 / 5.0, 0);
		glScalef(0.2, 0.4, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 8 / 5.0, y, 0);
		glScalef(0.2, 0.6, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 8 / 5.0, y - 6 / 5.0, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 6 / 5.0, y, 0);
		glScalef(0.2, 1.0, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 6 / 5.0, y + 8 / 5.0, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 4 / 5.0, y - 1 / 5.0, 0);
		glScalef(0.2, 0.4, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 4 / 5.0, y + 5 / 5.0, 0);
		glScalef(0.2, 0.4, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	
	// Eyes
	glPushMatrix();
		glTranslatef(x - 4 / 5.0, y + 2 / 5.0, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(0, 0, 0);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 4 / 5.0, y + 2 / 5.0, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(0, 0, 0);
		draw::cube();
	glPopMatrix();
}

void enemy::drawEnemy1() {
	// left side
	glPushMatrix();
		glTranslatef(x - 7 / 5.0, y + 1 / 5.0, 0);
		glScalef(0.2, 0.4, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 7 / 5.0, y - 4 / 5.0, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 5 / 5.0, y + 1 / 5.0, 0);
		glScalef(0.2, 0.8, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 5 / 5.0, y - 6 / 5.0, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 3 / 5.0, y + 5 / 5.0, 0);
		glScalef(0.2, 0.4, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 3 / 5.0, y, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	// body
	glPushMatrix();
		glTranslatef(x, y + 2 / 5.0, 0);
		glScalef(0.4, 1.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
		
	// right side
	glPushMatrix();
	glTranslatef(x + 7 / 5.0, y + 1 / 5.0, 0);
		glScalef(0.2, 0.4, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 7 / 5.0, y - 4 / 5.0, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 5 / 5.0, y + 1 / 5.0, 0);
		glScalef(0.2, 0.8, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 5 / 5.0, y - 6 / 5.0, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 3 / 5.0, y + 5 / 5.0, 0);
		glScalef(0.2, 0.4, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 3 / 5.0, y, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	
	// Eyes
	glPushMatrix();
		glTranslatef(x - 3 / 5.0, y + 2 / 5.0, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(0, 0, 0);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 3 / 5.0, y + 2 / 5.0, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(0, 0, 0);
		draw::cube();
	glPopMatrix();
}

void enemy::drawEnemy1B() {
	// left side
	glPushMatrix();
		glTranslatef(x - 7 / 5.0, y + 1 / 5.0, 0);
		glScalef(0.2, 0.4, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 7 / 5.0, y - 4 / 5.0, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 5 / 5.0, y + 2 / 5.0, 0);
		glScalef(0.2, 0.6, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 5 / 5.0, y - 4 / 5.0, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 3 / 5.0, y + 5 / 5.0, 0);
		glScalef(0.2, 0.4, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 3 / 5.0, y - 1 / 5.0, 0);
		glScalef(0.2, 0.4, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 3 / 5.0, y - 6 / 5.0, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	
	// body
	glPushMatrix();
		glTranslatef(x, y + 2 / 5.0, 0);
		glScalef(0.4, 1.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x, y - 4 / 5.0, 0);
		glScalef(0.4, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	
	// right side
	glPushMatrix();
		glTranslatef(x + 7 / 5.0, y + 1 / 5.0, 0);
		glScalef(0.2, 0.4, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 7 / 5.0, y - 4 / 5.0, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 5 / 5.0, y + 2 / 5.0, 0);
		glScalef(0.2, 0.6, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 5 / 5.0, y - 4 / 5.0, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 3 / 5.0, y + 5 / 5.0, 0);
		glScalef(0.2, 0.4, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 3 / 5.0, y - 1 / 5.0, 0);
		glScalef(0.2, 0.4, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 3 / 5.0, y - 6 / 5.0, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	
	// Eyes
	glPushMatrix();
		glTranslatef(x - 3 / 5.0, y + 2 / 5.0, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(0, 0, 0);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 3 / 5.0, y + 2 / 5.0, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(0, 0, 0);
		draw::cube();
	glPopMatrix();
}

void enemy::drawEnemy2() {
	// left side
	glPushMatrix();
		glTranslatef(x - 11 / 5.0, y + 2 / 5.0, 0);
		glScalef(0.2, 0.6, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 8 / 5.0, y + 3 / 5.0, 0);
		glScalef(0.4, 0.8, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 6 / 5.0, y - 6 / 5.0, 0);
		glScalef(0.4, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 8 / 5.0, y - 4 / 5.0, 0);
		glScalef(0.4, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 5 / 5.0, y - 1 / 5.0, 0);
		glScalef(0.6, 0.4, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 5 / 5.0, y + 5 / 5.0, 0);
		glScalef(0.2, 0.4, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 3 / 5.0, y + 6 / 5.0, 0);
		glScalef(0.2, 0.6, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
			
	// body
	glPushMatrix();
		glTranslatef(x, y + 5 / 5.0, 0);
		glScalef(0.4, 1.0, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x, y - 4 / 5.0, 0);
		glScalef(0.4, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
			
	// right side
	glPushMatrix();
		glTranslatef(x + 11 / 5.0, y + 2 / 5.0, 0);
		glScalef(0.2, 0.6, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 8 / 5.0, y + 3 / 5.0, 0);
		glScalef(0.4, 0.8, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 6 / 5.0, y - 6 / 5.0, 0);
		glScalef(0.4, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 8 / 5.0, y - 4 / 5.0, 0);
		glScalef(0.4, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(x + 5 / 5.0, y - 1 / 5.0, 0);
		glScalef(0.6, 0.4, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 5 / 5.0, y + 5 / 5.0, 0);
		glScalef(0.2, 0.4, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 3 / 5.0, y + 6 / 5.0, 0);
		glScalef(0.2, 0.6, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	
	// Eyes
	glPushMatrix();
		glTranslatef(x - 4 / 5.0, y + 2 / 5.0, 0);
		glScalef(0.4, 0.2, 0.6);
		glColor3f(0, 0, 0);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 4 / 5.0, y + 2 / 5.0, 0);
		glScalef(0.4, 0.2, 0.6);
		glColor3f(0, 0, 0);
		draw::cube();
	glPopMatrix();
}

void enemy::drawEnemy2B() {
	glPushMatrix();
		glTranslatef(x - 11 / 5.0, y + 2 / 5.0, 0);
		glScalef(0.2, 0.6, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 8 / 5.0, y + 3 / 5.0, 0);
		glScalef(0.4, 0.8, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 10 / 5.0, y - 6 / 5.0, 0);
		glScalef(0.4, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 6 / 5.0, y - 4 / 5.0, 0);
		glScalef(0.4, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 4 / 5.0, y - 1 / 5.0, 0);
		glScalef(0.4, 0.4, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 5 / 5.0, y + 5 / 5.0, 0);
		glScalef(0.2, 0.4, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 3 / 5.0, y + 6 / 5.0, 0);
		glScalef(0.2, 0.6, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	
	// body
	glPushMatrix();
		glTranslatef(x, y + 5 / 5.0, 0);
		glScalef(0.4, 1.0, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x, y - 4 / 5.0, 0);
		glScalef(0.4, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	
	// right side
	glPushMatrix();
		glTranslatef(x + 11 / 5.0, y + 2 / 5.0, 0);
		glScalef(0.2, 0.6, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 8 / 5.0, y + 3 / 5.0, 0);
		glScalef(0.4, 0.8, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 10 / 5.0, y - 6 / 5.0, 0);
		glScalef(0.4, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 6 / 5.0, y - 4 / 5.0, 0);
		glScalef(0.4, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 4 / 5.0, y - 1 / 5.0, 0);
		glScalef(0.4, 0.4, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 5 / 5.0, y + 5 / 5.0, 0);
		glScalef(0.2, 0.4, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 3 / 5.0, y + 6 / 5.0, 0);
		glScalef(0.2, 0.6, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	
	// Eyes
	glPushMatrix();
		glTranslatef(x - 4 / 5.0, y + 2 / 5.0, 0);
		glScalef(0.4, 0.2, 0.6);
		glColor3f(0, 0, 0);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 4 / 5.0, y + 2 / 5.0, 0);
		glScalef(0.4, 0.2, 0.6);
		glColor3f(0, 0, 0);
		draw::cube();
	glPopMatrix();
}

void enemy::drawEnemy3() {
	// left side
	glPushMatrix();
		glTranslatef(x - 9 / 5.0, y - 2 / 5.0, 0);
		glScalef(0.2, 0.6, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 7 / 5.0, y + 1 / 5.0, 0);
		glScalef(0.2, 0.4, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 5 / 5.0, y + 1 / 5.0, 0);
		glScalef(0.2, 0.4, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 5 / 5.0, y + 1 / 5.0, 0);
		glScalef(0.2, 0.8, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 5 / 5.0, y + 8 / 5.0, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 5 / 5.0, y - 6 / 5.0, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 3 / 5.0, y - 2 / 5.0, 0);
		glScalef(0.2, 0.6, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 3 / 5.0, y + 5 / 5.0, 0);
		glScalef(0.2, 0.4, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	
	// body
	glPushMatrix();
		glTranslatef(x, y + 1 / 5.0, 0);
		glScalef(0.4, 0.8, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	
	// right side
	glPushMatrix();
		glTranslatef(x + 9 / 5.0, y - 2 / 5.0, 0);
		glScalef(0.2, 0.6, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 7 / 5.0, y + 1 / 5.0, 0);
		glScalef(0.2, 0.4, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 5 / 5.0, y + 1 / 5.0, 0);
		glScalef(0.2, 0.4, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 5 / 5.0, y + 1 / 5.0, 0);
		glScalef(0.2, 0.8, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 5 / 5.0, y + 8 / 5.0, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 5 / 5.0, y - 6 / 5.0, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 3 / 5.0, y - 2 / 5.0, 0);
		glScalef(0.2, 0.6, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 3 / 5.0, y + 5 / 5.0, 0);
		glScalef(0.2, 0.4, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	
	// Eyes
	glPushMatrix();
		glTranslatef(x - 3 / 5.0, y + 2 / 5.0, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(0, 0, 0);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 3 / 5.0, y + 2 / 5.0, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(0, 0, 0);
		draw::cube();
	glPopMatrix();
}

void enemy::drawEnemy3B() {
	glPushMatrix();
		glTranslatef(x - 9 / 5.0, y - 2 / 5.0, 0);
		glScalef(0.2, 0.6, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 7 / 5.0, y + 1 / 5.0, 0);
		glScalef(0.2, 0.4, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 5 / 5.0, y + 1 / 5.0, 0);
		glScalef(0.2, 0.8, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 5 / 5.0, y - 6 / 5.0, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 3 / 5.0, y + 4 / 5.0, 0);
		glScalef(0.2, 0.6, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 3 / 5.0, y - 4 / 5.0, 0);
		glScalef(0.2, 0.6, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	// body
	glPushMatrix();
		glTranslatef(x, y + 1 / 5.0, 0);
		glScalef(0.4, 0.8, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();

	// right side
	glPushMatrix();
		glTranslatef(x + 9 / 5.0, y - 2 / 5.0, 0);
		glScalef(0.2, 0.6, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 7 / 5.0, y + 1 / 5.0, 0);
		glScalef(0.2, 0.4, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 5 / 5.0, y + 1 / 5.0, 0);
		glScalef(0.2, 0.8, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 5 / 5.0, y - 6 / 5.0, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 3 / 5.0, y + 4 / 5.0, 0);
		glScalef(0.2, 0.6, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 3 / 5.0, y - 4 / 5.0, 0);
		glScalef(0.2, 0.6, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	
	// Eyes
	glPushMatrix();
		glTranslatef(x - 3 / 5.0, y, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(0, 0, 0);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 3 / 5.0, y, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(0, 0, 0);
		draw::cube();
	glPopMatrix();
}

void enemy::drawEnemy4() {
	glPushMatrix();
		glTranslatef(x - 6 / 5.0, y + 7 / 5.0, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 6 / 5.0, y + 2 / 5.0, 0);
		glScalef(0.2, 0.4, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 6 / 5.0, y - 4 / 5.0, 0);
		glScalef(0.2, 0.4, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 4 / 5.0, y + 2 / 5.0, 0);
		glScalef(0.2, 0.8, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 2 / 5.0, y + 5 / 5.0, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 2 / 5.0, y - 2 / 5.0, 0);
		glScalef(0.2, 0.4, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 3 / 5.0, y - 7 / 5.0, 0);
		glScalef(0.4, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	// body
	glPushMatrix();
		glTranslatef(x, y + 2 / 5.0, 0);
		glScalef(0.2, 0.8, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	// right side
	glPushMatrix();
		glTranslatef(x + 6 / 5.0, y + 7 / 5.0, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 6 / 5.0, y + 2 / 5.0, 0);
		glScalef(0.2, 0.4, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 6 / 5.0, y - 4 / 5.0, 0);
		glScalef(0.2, 0.4, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 4 / 5.0, y + 2 / 5.0, 0);
		glScalef(0.2, 0.8, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 2 / 5.0, y + 5 / 5.0, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 2 / 5.0, y - 2 / 5.0, 0);
		glScalef(0.2, 0.4, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 3 / 5.0, y - 7 / 5.0, 0);
		glScalef(0.4, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	
	// Eyes
	glPushMatrix();
		glTranslatef(x - 2 / 5.0, y + 2 / 5.0, 0);
		glScalef(0.2, 0.4, 0.6);
		glColor3f(0, 0, 0);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 2 / 5.0, y + 2 / 5.0, 0);
		glScalef(0.2, 0.4, 0.6);
		glColor3f(0, 0, 0);
		draw::cube();
	glPopMatrix();
}

void enemy::drawEnemy4B() {
	// left side
	glPushMatrix();
		glTranslatef(x - 6 / 5.0, y + 7 / 5.0, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 6 / 5.0, y + 2 / 5.0, 0);
		glScalef(0.2, 0.4, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 6 / 5.0, y - 7 / 5.0, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 4 / 5.0, y + 2 / 5.0, 0);
		glScalef(0.2, 0.8, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 4 / 5.0, y - 5 / 5.0, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 2 / 5.0, y - 2 / 5.0, 0);
		glScalef(0.2, 0.4, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 2 / 5.0, y + 5 / 5.0, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	
	// body
	glPushMatrix();
		glTranslatef(x, y + 2 / 5.0, 0);
		glScalef(0.2, 0.8, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	
	// right side
	glPushMatrix();
		glTranslatef(x + 6 / 5.0, y + 7 / 5.0, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 6 / 5.0, y + 2 / 5.0, 0);
		glScalef(0.2, 0.4, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 6 / 5.0, y - 7 / 5.0, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 4 / 5.0, y + 2 / 5.0, 0);
		glScalef(0.2, 0.8, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 4 / 5.0, y - 5 / 5.0, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 2 / 5.0, y - 2 / 5.0, 0);
		glScalef(0.2, 0.4, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 2 / 5.0, y + 5 / 5.0, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	
	// Eyes
	glPushMatrix();
		glTranslatef(x - 2 / 5.0, y + 2 / 5.0, 0);
		glScalef(0.2, 0.4, 0.6);
		glColor3f(0, 0, 0);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 2 / 5.0, y + 2 / 5.0, 0);
		glScalef(0.2, 0.4, 0.6);
		glColor3f(0, 0, 0);
		draw::cube();
	glPopMatrix();
}

void enemy::drawEnemy5() {
	// left side
	glPushMatrix();
		glTranslatef(x - 8 / 5.0, y + 1 / 5.0, 0);
		glScalef(0.2, 0.4, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 8 / 5.0, y - 7 / 5.0, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 6 / 5.0, y + 3 / 5.0, 0);
		glScalef(0.2, 0.6, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 6 / 5.0, y - 5 / 5.0, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 3 / 5.0, y + 6 / 5.0, 0);
		glScalef(0.4, 0.4, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 4 / 5.0, y + 1 / 5.0, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 4 / 5.0, y - 3 / 5.0, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 2 / 5.0, y, 0);
		glScalef(0.2, 0.4, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	
	// body
	glPushMatrix();
		glTranslatef(x, y + 1.5 / 5.0, 0);
		glScalef(0.2, 1.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	
	// right side
	glPushMatrix();
		glTranslatef(x + 8 / 5.0, y + 1 / 5.0, 0);
		glScalef(0.2, 0.4, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 8 / 5.0, y - 7 / 5.0, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 6 / 5.0, y + 3 / 5.0, 0);
		glScalef(0.2, 0.6, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 6 / 5.0, y - 5 / 5.0, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 3 / 5.0, y + 6 / 5.0, 0);
		glScalef(0.4, 0.4, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 4 / 5.0, y + 1 / 5.0, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 4 / 5.0, y - 3 / 5.0, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 2 / 5.0, y, 0);
		glScalef(0.2, 0.4, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	
	// Eyes
	glPushMatrix();
		glTranslatef(x - 3 / 5.0, y + 3 / 5.0, 0);
		glScalef(0.4, 0.2, 0.6);
		glColor3f(0, 0, 0);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 3 / 5.0, y + 3 / 5.0, 0);
		glScalef(0.4, 0.2, 0.6);
		glColor3f(0, 0, 0);
		draw::cube();
	glPopMatrix();
}

void enemy::drawEnemy5B() {
	// left side
	glPushMatrix();
		glTranslatef(x - 8 / 5.0, y + 1 / 5.0, 0);
		glScalef(0.2, 0.4, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 6 / 5.0, y + 3 / 5.0, 0);
		glScalef(0.2, 0.6, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 6 / 5.0, y - 5 / 5.0, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 3 / 5.0, y + 6 / 5.0, 0);
		glScalef(0.4, 0.4, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 3 / 5.0, y - 8 / 5.0, 0);
		glScalef(0.4, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 4 / 5.0, y + 1 / 5.0, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 4 / 5.0, y - 3 / 5.0, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 2 / 5.0, y, 0);
		glScalef(0.2, 0.4, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	
	// body
	glPushMatrix();
		glTranslatef(x, y + 1.5 / 5.0, 0);
		glScalef(0.2, 1.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	
	// right side
	glPushMatrix();
		glTranslatef(x + 8 / 5.0, y + 1 / 5.0, 0);
		glScalef(0.2, 0.4, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 6 / 5.0, y + 3 / 5.0, 0);
		glScalef(0.2, 0.6, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 6 / 5.0, y - 5 / 5.0, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 3 / 5.0, y + 6 / 5.0, 0);
		glScalef(0.4, 0.4, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 3 / 5.0, y - 8 / 5.0, 0);
		glScalef(0.4, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 4 / 5.0, y + 1 / 5.0, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 4 / 5.0, y - 3 / 5.0, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 2 / 5.0, y, 0);
		glScalef(0.2, 0.4, 0.6);
		glColor3f(c.r, c.g, c.b);
		draw::cube();
	glPopMatrix();
	
	// Eyes
	glPushMatrix();
		glTranslatef(x - 3 / 5.0, y + 3 / 5.0, 0);
		glScalef(0.4, 0.2, 0.6);
		glColor3f(0, 0, 0);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 3 / 5.0, y + 3 / 5.0, 0);
		glScalef(0.4, 0.2, 0.6);
		glColor3f(0, 0, 0);
		draw::cube();
	glPopMatrix();
}

void enemy::draw(){

    if(y > 28)
        return;

	if(animationTimer.elapsed() > 0.4){
		animationTimer.reset();
		frame = !frame;
	}
	
	if(frame){
		// Enemy type 0
		if (type == 0)
			drawEnemy0();
		// Enemy type 1
		else if (type == 1)
			drawEnemy1();
		else if (type == 2)
			drawEnemy2();
		// Enemy type 3
		else if (type == 3)
			drawEnemy3();
		else if (type == 4)
			drawEnemy4();
		else if (type == 5)
			drawEnemy5();
	}
	else {
		// Enemy type 0
		if (type == 0)
			drawEnemy0B();
		else if (type == 1)
			drawEnemy1B();
		else if (type == 2)
			drawEnemy2B();
        else if (type == 3)
			drawEnemy3B();
		else if (type == 4)
			drawEnemy4B();
		else if (type == 5)
			drawEnemy5B();
	}
}
