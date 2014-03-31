#include "enemy.hpp"

enemy::enemy(){
    dir = 1;
    
    animationTimer.reset();
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
	
	if(animationTimer.elapsed() > 0.4){
		animationTimer.reset();
		frame = !frame;
	}
	if(frame){
		// left side
		glPushMatrix();
			glTranslatef(x - 10 / 5.0, y - 2 / 5.0, 0);
			glScalef(0.2, 0.6, 1);
			glColor3f(1.0f, 0, 0);
			draw::cube();
		glPopMatrix();
		glPushMatrix();
			glTranslatef(x - 8 / 5.0, y + 1 / 5.0, 0);
			glScalef(0.2, 0.4, 1);
			glColor3f(1.0f, 0, 0);
			draw::cube();
		glPopMatrix();
		glPushMatrix();
			glTranslatef(x - 6 / 5.0, y, 0);
			glScalef(0.2, 1.0, 1);
			glColor3f(1.0f, 0, 0);
			draw::cube();
		glPopMatrix();
		glPushMatrix();
			glTranslatef(x - 6 / 5.0, y + 8 / 5.0, 0);
			glScalef(0.2, 0.2, 1);
			glColor3f(1.0f, 0, 0);
			draw::cube();
		glPopMatrix();
		glPushMatrix();
			glTranslatef(x - 4 / 5.0, y, 0);
			glScalef(0.2, 0.2, 1);
			glColor3f(1.0f, 0, 0);
			draw::cube();
		glPopMatrix();
		glPushMatrix();
			glTranslatef(x - 4 / 5.0, y + 5 / 5.0, 0);
			glScalef(0.2, 0.4, 1);
			glColor3f(1.0f, 0, 0);
			draw::cube();
		glPopMatrix();
		// body
		glPushMatrix();
			glTranslatef(x, y + 1 / 5.0, 0);
			glScalef(0.6, 0.8, 1);
			glColor3f(1.0f, 0, 0);
			draw::cube();
		glPopMatrix();
		
		// right side
		glPushMatrix();
			glTranslatef(x + 10 / 5.0, y - 2 / 5.0, 0);
			glScalef(0.2, 0.6, 1);
			glColor3f(1.0f, 0, 0);
			draw::cube();
		glPopMatrix();
		glPushMatrix();
			glTranslatef(x + 8 / 5.0, y + 1 / 5.0, 0);
			glScalef(0.2, 0.4, 1);
			glColor3f(1.0f, 0, 0);
			draw::cube();
		glPopMatrix();
		glPushMatrix();
			glTranslatef(x + 6 / 5.0, y, 0);
			glScalef(0.2, 1.0, 1);
			glColor3f(1.0f, 0, 0);
			draw::cube();
		glPopMatrix();
		glPushMatrix();
			glTranslatef(x + 6 / 5.0, y + 8 / 5.0, 0);
			glScalef(0.2, 0.2, 1);
			glColor3f(1.0f, 0, 0);
			draw::cube();
		glPopMatrix();
		glPushMatrix();
			glTranslatef(x + 4 / 5.0, y, 0);
			glScalef(0.2, 0.2, 1);
			glColor3f(1.0f, 0, 0);
			draw::cube();
		glPopMatrix();
		glPushMatrix();
			glTranslatef(x + 4 / 5.0, y + 5 / 5.0, 0);
			glScalef(0.2, 0.4, 1);
			glColor3f(1.0f, 0, 0);
			draw::cube();
		glPopMatrix();
		
		glPushMatrix();
			glTranslatef(x - 3 / 5.0, y - 6 / 5.0, 0);
			glScalef(0.4, 0.2, 1);
			glColor3f(1.0f, 0, 0);
			draw::cube();
		glPopMatrix();
		glPushMatrix();
			glTranslatef(x + 3 / 5.0, y - 6 / 5.0, 0);
			glScalef(0.4, 0.2, 1);
			glColor3f(1.0f, 0, 0);
			draw::cube();
		glPopMatrix();
	}
	else {
		// Left side
		glPushMatrix();
			glTranslatef(x - 10 / 5.0, y + 3 / 5.0, 0);
			glScalef(0.2, 0.8, 1);
			glColor3f(1.0f, 0, 0);
			draw::cube();
		glPopMatrix();
		glPushMatrix();
			glTranslatef(x - 8 / 5.0, y, 0);
			glScalef(0.2, 0.6, 1);
			glColor3f(1.0f, 0, 0);
			draw::cube();
		glPopMatrix();
		glPushMatrix();
			glTranslatef(x - 8 / 5.0, y - 6 / 5.0, 0);
			glScalef(0.2, 0.2, 1);
			glColor3f(1.0f, 0, 0);
			draw::cube();
		glPopMatrix();
		glPushMatrix();
			glTranslatef(x - 6 / 5.0, y, 0);
			glScalef(0.2, 1.0, 1);
			glColor3f(1.0f, 0, 0);
			draw::cube();
		glPopMatrix();
		glPushMatrix();
			glTranslatef(x - 6 / 5.0, y + 8 / 5.0, 0);
			glScalef(0.2, 0.2, 1);
			glColor3f(1.0f, 0, 0);
			draw::cube();
		glPopMatrix();
		glPushMatrix();
			glTranslatef(x - 4 / 5.0, y - 1 / 5.0, 0);
			glScalef(0.2, 0.4, 1);
			glColor3f(1.0f, 0, 0);
			draw::cube();
		glPopMatrix();
		glPushMatrix();
			glTranslatef(x - 4 / 5.0, y + 5 / 5.0, 0);
			glScalef(0.2, 0.4, 1);
			glColor3f(1.0f, 0, 0);
			draw::cube();
		glPopMatrix();
		
		// body
		glPushMatrix();
			glTranslatef(x, y + 1 / 5.0, 0);
			glScalef(0.6, 0.8, 1);
			glColor3f(1.0f, 0, 0);
			draw::cube();
		glPopMatrix();
		
		// Right side
		glPushMatrix();
			glTranslatef(x + 10 / 5.0, y + 3 / 5.0, 0);
			glScalef(0.2, 0.4, 1);
			glColor3f(1.0f, 0, 0);
			draw::cube();
		glPopMatrix();
		glPushMatrix();
			glTranslatef(x + 8 / 5.0, y, 0);
			glScalef(0.2, 0.6, 1);
			glColor3f(1.0f, 0, 0);
			draw::cube();
		glPopMatrix();
		glPushMatrix();
			glTranslatef(x + 8 / 5.0, y - 6 / 5.0, 0);
			glScalef(0.2, 0.2, 1);
			glColor3f(1.0f, 0, 0);
			draw::cube();
		glPopMatrix();
		glPushMatrix();
			glTranslatef(x + 6 / 5.0, y, 0);
			glScalef(0.2, 1.0, 1);
			glColor3f(1.0f, 0, 0);
			draw::cube();
		glPopMatrix();
		glPushMatrix();
			glTranslatef(x + 6 / 5.0, y + 8 / 5.0, 0);
			glScalef(0.2, 0.2, 1);
			glColor3f(1.0f, 0, 0);
			draw::cube();
		glPopMatrix();
		glPushMatrix();
			glTranslatef(x + 4 / 5.0, y - 1 / 5.0, 0);
			glScalef(0.2, 0.4, 1);
			glColor3f(1.0f, 0, 0);
			draw::cube();
		glPopMatrix();
		glPushMatrix();
			glTranslatef(x + 4 / 5.0, y + 5 / 5.0, 0);
			glScalef(0.2, 0.4, 1);
			glColor3f(1.0f, 0, 0);
			draw::cube();
		glPopMatrix();
	}
	
	// Eyes
	glPushMatrix();
		glTranslatef(x - 4 / 5.0, y + 2 / 5.0, 0);
		glScalef(0.2, 0.2, 1);
		glColor3f(0, 0, 0);
		draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 4 / 5.0, y + 2 / 5.0, 0);
		glScalef(0.2, 0.2, 1);
		glColor3f(0, 0, 0);
		draw::cube();
	glPopMatrix();
}
