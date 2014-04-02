#include "enemy.hpp"

enemy::enemy(){
    dir = 1;
    c = magenta;
    type = 0;
    animationTimer.reset();
}

enemy::enemy(float x, float y, int t, int level){
    this->x = x;
    this->y = y;
    type = t;

    dir = 1;
    c = magenta;
    animationTimer.reset();

    h = 2;
    w = 2;

    scale = 1.0f;

    velocity = 0.2f + level*0.05;
    beenHit = false;
}

void enemy::update(){

    x += dir*velocity;
    if(dir > 0 && x > 37){
        dir = -1;
        y -= 3;
    }
    else if(dir < 0 && x < -37){
        dir = 1;
        y -= 3;
    }
}

void enemy::hit(){
    beenHit = true;
    deathTimer.reset();
}

void enemy::draw(){

    if(y > 28)
        return;

    if(beenHit){
        scale = (0.15 - deathTimer.elapsed())/0.15;
    }else{
        if(animationTimer.elapsed() > 0.4){
            animationTimer.reset();
            frame = !frame;
        }
    }

    glPushMatrix();
    
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
    glPopMatrix();
}

void enemy::drawEnemy0() {
	// left side
	glPushMatrix();
		glTranslatef(x - 10 / 5.0, y - 2 / 5.0, 0);
		glScalef(0.2, 0.6, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
		glPushMatrix();
		glTranslatef(x - 8 / 5.0, y + 1 / 5.0, 0);
		glScalef(0.2, 0.4, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 6 / 5.0, y, 0);
		glScalef(0.2, 1.0, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 6 / 5.0, y + 8 / 5.0, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 4 / 5.0, y - 1 / 5.0, 0);
		glScalef(0.2, 0.4, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 4 / 5.0, y + 5 / 5.0, 0);
		glScalef(0.2, 0.4, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	
	// body
	glPushMatrix();
		glTranslatef(x, y + 1 / 5.0, 0);
		glScalef(0.6, 0.8, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();

	// right side
	glPushMatrix();
		glTranslatef(x + 10 / 5.0, y - 2 / 5.0, 0);
		glScalef(0.2, 0.6, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 8 / 5.0, y + 1 / 5.0, 0);
		glScalef(0.2, 0.4, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 6 / 5.0, y, 0);
		glScalef(0.2, 1.0, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 6 / 5.0, y + 8 / 5.0, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 4 / 5.0, y - 1 / 5.0, 0);
		glScalef(0.2, 0.4, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 4 / 5.0, y + 5 / 5.0, 0);
		glScalef(0.2, 0.4, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(x - 3 / 5.0, y - 6 / 5.0, 0);
		glScalef(0.4, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 3 / 5.0, y - 6 / 5.0, 0);
		glScalef(0.4, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();

	// Eyes
	glPushMatrix();
		glTranslatef(x - 4 / 5.0, y + 2 / 5.0, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(0, 0, 0);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 4 / 5.0, y + 2 / 5.0, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(0, 0, 0);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
}

void enemy::drawEnemy0B() {
	// Left side
	glPushMatrix();
		glTranslatef(x - 10 / 5.0, y + 3 / 5.0, 0);
		glScalef(0.2, 0.8, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 8 / 5.0, y, 0);
		glScalef(0.2, 0.6, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 8 / 5.0, y - 6 / 5.0, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 6 / 5.0, y, 0);
		glScalef(0.2, 1.0, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 6 / 5.0, y + 8 / 5.0, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 4 / 5.0, y - 1 / 5.0, 0);
		glScalef(0.2, 0.4, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 4 / 5.0, y + 5 / 5.0, 0);
		glScalef(0.2, 0.4, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	
	// body
	glPushMatrix();
		glTranslatef(x, y + 1 / 5.0, 0);
		glScalef(0.6, 0.8, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	
	// Right side
	glPushMatrix();
		glTranslatef(x + 10 / 5.0, y + 3 / 5.0, 0);
		glScalef(0.2, 0.4, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 8 / 5.0, y, 0);
		glScalef(0.2, 0.6, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 8 / 5.0, y - 6 / 5.0, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 6 / 5.0, y, 0);
		glScalef(0.2, 1.0, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 6 / 5.0, y + 8 / 5.0, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 4 / 5.0, y - 1 / 5.0, 0);
		glScalef(0.2, 0.4, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 4 / 5.0, y + 5 / 5.0, 0);
		glScalef(0.2, 0.4, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	
	// Eyes
	glPushMatrix();
		glTranslatef(x - 4 / 5.0, y + 2 / 5.0, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(0, 0, 0);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 4 / 5.0, y + 2 / 5.0, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(0, 0, 0);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
}

void enemy::drawEnemy1() {
	// left side
	glPushMatrix();
		glTranslatef(x - 7 / 5.0, y + 1 / 5.0, 0);
		glScalef(0.2, 0.4, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 7 / 5.0, y - 4 / 5.0, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 5 / 5.0, y + 1 / 5.0, 0);
		glScalef(0.2, 0.8, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 5 / 5.0, y - 6 / 5.0, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 3 / 5.0, y + 5 / 5.0, 0);
		glScalef(0.2, 0.4, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 3 / 5.0, y, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	// body
	glPushMatrix();
		glTranslatef(x, y + 2 / 5.0, 0);
		glScalef(0.4, 1.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
		
	// right side
	glPushMatrix();
	glTranslatef(x + 7 / 5.0, y + 1 / 5.0, 0);
		glScalef(0.2, 0.4, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 7 / 5.0, y - 4 / 5.0, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 5 / 5.0, y + 1 / 5.0, 0);
		glScalef(0.2, 0.8, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 5 / 5.0, y - 6 / 5.0, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 3 / 5.0, y + 5 / 5.0, 0);
		glScalef(0.2, 0.4, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 3 / 5.0, y, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	
	// Eyes
	glPushMatrix();
		glTranslatef(x - 3 / 5.0, y + 2 / 5.0, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(0, 0, 0);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 3 / 5.0, y + 2 / 5.0, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(0, 0, 0);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
}

void enemy::drawEnemy1B() {
	// left side
	glPushMatrix();
		glTranslatef(x - 7 / 5.0, y + 1 / 5.0, 0);
		glScalef(0.2, 0.4, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 7 / 5.0, y - 4 / 5.0, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 5 / 5.0, y + 2 / 5.0, 0);
		glScalef(0.2, 0.6, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 5 / 5.0, y - 4 / 5.0, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 3 / 5.0, y + 5 / 5.0, 0);
		glScalef(0.2, 0.4, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 3 / 5.0, y - 1 / 5.0, 0);
		glScalef(0.2, 0.4, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 3 / 5.0, y - 6 / 5.0, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	
	// body
	glPushMatrix();
		glTranslatef(x, y + 2 / 5.0, 0);
		glScalef(0.4, 1.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x, y - 4 / 5.0, 0);
		glScalef(0.4, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	
	// right side
	glPushMatrix();
		glTranslatef(x + 7 / 5.0, y + 1 / 5.0, 0);
		glScalef(0.2, 0.4, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 7 / 5.0, y - 4 / 5.0, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 5 / 5.0, y + 2 / 5.0, 0);
		glScalef(0.2, 0.6, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 5 / 5.0, y - 4 / 5.0, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 3 / 5.0, y + 5 / 5.0, 0);
		glScalef(0.2, 0.4, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 3 / 5.0, y - 1 / 5.0, 0);
		glScalef(0.2, 0.4, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 3 / 5.0, y - 6 / 5.0, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	
	// Eyes
	glPushMatrix();
		glTranslatef(x - 3 / 5.0, y + 2 / 5.0, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(0, 0, 0);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 3 / 5.0, y + 2 / 5.0, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(0, 0, 0);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
}

void enemy::drawEnemy2() {
	// left side
	glPushMatrix();
		glTranslatef(x - 11 / 5.0, y + 2 / 5.0, 0);
		glScalef(0.2, 0.6, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 8 / 5.0, y + 3 / 5.0, 0);
		glScalef(0.4, 0.8, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 6 / 5.0, y - 6 / 5.0, 0);
		glScalef(0.4, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 8 / 5.0, y - 4 / 5.0, 0);
		glScalef(0.4, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 5 / 5.0, y - 1 / 5.0, 0);
		glScalef(0.6, 0.4, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 5 / 5.0, y + 5 / 5.0, 0);
		glScalef(0.2, 0.4, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 3 / 5.0, y + 6 / 5.0, 0);
		glScalef(0.2, 0.6, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
			
	// body
	glPushMatrix();
		glTranslatef(x, y + 5 / 5.0, 0);
		glScalef(0.4, 1.0, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x, y - 4 / 5.0, 0);
		glScalef(0.4, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
			
	// right side
	glPushMatrix();
		glTranslatef(x + 11 / 5.0, y + 2 / 5.0, 0);
		glScalef(0.2, 0.6, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 8 / 5.0, y + 3 / 5.0, 0);
		glScalef(0.4, 0.8, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 6 / 5.0, y - 6 / 5.0, 0);
		glScalef(0.4, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 8 / 5.0, y - 4 / 5.0, 0);
		glScalef(0.4, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
	glTranslatef(x + 5 / 5.0, y - 1 / 5.0, 0);
		glScalef(0.6, 0.4, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 5 / 5.0, y + 5 / 5.0, 0);
		glScalef(0.2, 0.4, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 3 / 5.0, y + 6 / 5.0, 0);
		glScalef(0.2, 0.6, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	
	// Eyes
	glPushMatrix();
		glTranslatef(x - 4 / 5.0, y + 2 / 5.0, 0);
		glScalef(0.4, 0.2, 0.6);
		glColor3f(0, 0, 0);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 4 / 5.0, y + 2 / 5.0, 0);
		glScalef(0.4, 0.2, 0.6);
		glColor3f(0, 0, 0);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
}

void enemy::drawEnemy2B() {
	glPushMatrix();
		glTranslatef(x - 11 / 5.0, y + 2 / 5.0, 0);
		glScalef(0.2, 0.6, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 8 / 5.0, y + 3 / 5.0, 0);
		glScalef(0.4, 0.8, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 10 / 5.0, y - 6 / 5.0, 0);
		glScalef(0.4, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 6 / 5.0, y - 4 / 5.0, 0);
		glScalef(0.4, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 4 / 5.0, y - 1 / 5.0, 0);
		glScalef(0.4, 0.4, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 5 / 5.0, y + 5 / 5.0, 0);
		glScalef(0.2, 0.4, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 3 / 5.0, y + 6 / 5.0, 0);
		glScalef(0.2, 0.6, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	
	// body
	glPushMatrix();
		glTranslatef(x, y + 5 / 5.0, 0);
		glScalef(0.4, 1.0, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x, y - 4 / 5.0, 0);
		glScalef(0.4, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	
	// right side
	glPushMatrix();
		glTranslatef(x + 11 / 5.0, y + 2 / 5.0, 0);
		glScalef(0.2, 0.6, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 8 / 5.0, y + 3 / 5.0, 0);
		glScalef(0.4, 0.8, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 10 / 5.0, y - 6 / 5.0, 0);
		glScalef(0.4, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 6 / 5.0, y - 4 / 5.0, 0);
		glScalef(0.4, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 4 / 5.0, y - 1 / 5.0, 0);
		glScalef(0.4, 0.4, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 5 / 5.0, y + 5 / 5.0, 0);
		glScalef(0.2, 0.4, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 3 / 5.0, y + 6 / 5.0, 0);
		glScalef(0.2, 0.6, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	
	// Eyes
	glPushMatrix();
		glTranslatef(x - 4 / 5.0, y + 2 / 5.0, 0);
		glScalef(0.4, 0.2, 0.6);
		glColor3f(0, 0, 0);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 4 / 5.0, y + 2 / 5.0, 0);
		glScalef(0.4, 0.2, 0.6);
		glColor3f(0, 0, 0);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
}

void enemy::drawEnemy3() {
	// left side
	glPushMatrix();
		glTranslatef(x - 9 / 5.0, y - 2 / 5.0, 0);
		glScalef(0.2, 0.6, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 7 / 5.0, y + 1 / 5.0, 0);
		glScalef(0.2, 0.4, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 5 / 5.0, y + 1 / 5.0, 0);
		glScalef(0.2, 0.4, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 5 / 5.0, y + 1 / 5.0, 0);
		glScalef(0.2, 0.8, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 5 / 5.0, y + 8 / 5.0, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 5 / 5.0, y - 6 / 5.0, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 3 / 5.0, y - 2 / 5.0, 0);
		glScalef(0.2, 0.6, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 3 / 5.0, y + 5 / 5.0, 0);
		glScalef(0.2, 0.4, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	
	// body
	glPushMatrix();
		glTranslatef(x, y + 1 / 5.0, 0);
		glScalef(0.4, 0.8, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	
	// right side
	glPushMatrix();
		glTranslatef(x + 9 / 5.0, y - 2 / 5.0, 0);
		glScalef(0.2, 0.6, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 7 / 5.0, y + 1 / 5.0, 0);
		glScalef(0.2, 0.4, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 5 / 5.0, y + 1 / 5.0, 0);
		glScalef(0.2, 0.4, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 5 / 5.0, y + 1 / 5.0, 0);
		glScalef(0.2, 0.8, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 5 / 5.0, y + 8 / 5.0, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 5 / 5.0, y - 6 / 5.0, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 3 / 5.0, y - 2 / 5.0, 0);
		glScalef(0.2, 0.6, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 3 / 5.0, y + 5 / 5.0, 0);
		glScalef(0.2, 0.4, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	
	// Eyes
	glPushMatrix();
		glTranslatef(x - 3 / 5.0, y + 2 / 5.0, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(0, 0, 0);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 3 / 5.0, y + 2 / 5.0, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(0, 0, 0);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
}

void enemy::drawEnemy3B() {
	glPushMatrix();
		glTranslatef(x - 9 / 5.0, y - 2 / 5.0, 0);
		glScalef(0.2, 0.6, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 7 / 5.0, y + 1 / 5.0, 0);
		glScalef(0.2, 0.4, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 5 / 5.0, y + 1 / 5.0, 0);
		glScalef(0.2, 0.8, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 5 / 5.0, y - 6 / 5.0, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 3 / 5.0, y + 4 / 5.0, 0);
		glScalef(0.2, 0.6, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 3 / 5.0, y - 4 / 5.0, 0);
		glScalef(0.2, 0.6, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	// body
	glPushMatrix();
		glTranslatef(x, y + 1 / 5.0, 0);
		glScalef(0.4, 0.8, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();

	// right side
	glPushMatrix();
		glTranslatef(x + 9 / 5.0, y - 2 / 5.0, 0);
		glScalef(0.2, 0.6, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 7 / 5.0, y + 1 / 5.0, 0);
		glScalef(0.2, 0.4, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 5 / 5.0, y + 1 / 5.0, 0);
		glScalef(0.2, 0.8, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 5 / 5.0, y - 6 / 5.0, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 3 / 5.0, y + 4 / 5.0, 0);
		glScalef(0.2, 0.6, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 3 / 5.0, y - 4 / 5.0, 0);
		glScalef(0.2, 0.6, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	
	// Eyes
	glPushMatrix();
		glTranslatef(x - 3 / 5.0, y, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(0, 0, 0);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 3 / 5.0, y, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(0, 0, 0);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
}

void enemy::drawEnemy4() {
	glPushMatrix();
		glTranslatef(x - 6 / 5.0, y + 7 / 5.0, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 6 / 5.0, y + 2 / 5.0, 0);
		glScalef(0.2, 0.4, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 6 / 5.0, y - 4 / 5.0, 0);
		glScalef(0.2, 0.4, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 4 / 5.0, y + 2 / 5.0, 0);
		glScalef(0.2, 0.8, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 2 / 5.0, y + 5 / 5.0, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 2 / 5.0, y - 2 / 5.0, 0);
		glScalef(0.2, 0.4, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 3 / 5.0, y - 7 / 5.0, 0);
		glScalef(0.4, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	// body
	glPushMatrix();
		glTranslatef(x, y + 2 / 5.0, 0);
		glScalef(0.2, 0.8, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	// right side
	glPushMatrix();
		glTranslatef(x + 6 / 5.0, y + 7 / 5.0, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 6 / 5.0, y + 2 / 5.0, 0);
		glScalef(0.2, 0.4, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 6 / 5.0, y - 4 / 5.0, 0);
		glScalef(0.2, 0.4, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 4 / 5.0, y + 2 / 5.0, 0);
		glScalef(0.2, 0.8, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 2 / 5.0, y + 5 / 5.0, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 2 / 5.0, y - 2 / 5.0, 0);
		glScalef(0.2, 0.4, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 3 / 5.0, y - 7 / 5.0, 0);
		glScalef(0.4, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	
	// Eyes
	glPushMatrix();
		glTranslatef(x - 2 / 5.0, y + 2 / 5.0, 0);
		glScalef(0.2, 0.4, 0.6);
		glColor3f(0, 0, 0);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 2 / 5.0, y + 2 / 5.0, 0);
		glScalef(0.2, 0.4, 0.6);
		glColor3f(0, 0, 0);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
}

void enemy::drawEnemy4B() {
	// left side
	glPushMatrix();
		glTranslatef(x - 6 / 5.0, y + 7 / 5.0, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 6 / 5.0, y + 2 / 5.0, 0);
		glScalef(0.2, 0.4, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 6 / 5.0, y - 7 / 5.0, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 4 / 5.0, y + 2 / 5.0, 0);
		glScalef(0.2, 0.8, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 4 / 5.0, y - 5 / 5.0, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 2 / 5.0, y - 2 / 5.0, 0);
		glScalef(0.2, 0.4, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 2 / 5.0, y + 5 / 5.0, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	
	// body
	glPushMatrix();
		glTranslatef(x, y + 2 / 5.0, 0);
		glScalef(0.2, 0.8, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	
	// right side
	glPushMatrix();
		glTranslatef(x + 6 / 5.0, y + 7 / 5.0, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 6 / 5.0, y + 2 / 5.0, 0);
		glScalef(0.2, 0.4, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 6 / 5.0, y - 7 / 5.0, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 4 / 5.0, y + 2 / 5.0, 0);
		glScalef(0.2, 0.8, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 4 / 5.0, y - 5 / 5.0, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 2 / 5.0, y - 2 / 5.0, 0);
		glScalef(0.2, 0.4, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 2 / 5.0, y + 5 / 5.0, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	
	// Eyes
	glPushMatrix();
		glTranslatef(x - 2 / 5.0, y + 2 / 5.0, 0);
		glScalef(0.2, 0.4, 0.6);
		glColor3f(0, 0, 0);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 2 / 5.0, y + 2 / 5.0, 0);
		glScalef(0.2, 0.4, 0.6);
		glColor3f(0, 0, 0);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
}

void enemy::drawEnemy5() {
	// left side
	glPushMatrix();
		glTranslatef(x - 8 / 5.0, y + 1 / 5.0, 0);
		glScalef(0.2, 0.4, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 8 / 5.0, y - 7 / 5.0, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 6 / 5.0, y + 3 / 5.0, 0);
		glScalef(0.2, 0.6, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 6 / 5.0, y - 5 / 5.0, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 3 / 5.0, y + 6 / 5.0, 0);
		glScalef(0.4, 0.4, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 4 / 5.0, y + 1 / 5.0, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 4 / 5.0, y - 3 / 5.0, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 2 / 5.0, y, 0);
		glScalef(0.2, 0.4, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	
	// body
	glPushMatrix();
		glTranslatef(x, y + 1.5 / 5.0, 0);
		glScalef(0.2, 1.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	
	// right side
	glPushMatrix();
		glTranslatef(x + 8 / 5.0, y + 1 / 5.0, 0);
		glScalef(0.2, 0.4, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 8 / 5.0, y - 7 / 5.0, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 6 / 5.0, y + 3 / 5.0, 0);
		glScalef(0.2, 0.6, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 6 / 5.0, y - 5 / 5.0, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 3 / 5.0, y + 6 / 5.0, 0);
		glScalef(0.4, 0.4, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 4 / 5.0, y + 1 / 5.0, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 4 / 5.0, y - 3 / 5.0, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 2 / 5.0, y, 0);
		glScalef(0.2, 0.4, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	
	// Eyes
	glPushMatrix();
		glTranslatef(x - 3 / 5.0, y + 3 / 5.0, 0);
		glScalef(0.4, 0.2, 0.6);
		glColor3f(0, 0, 0);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 3 / 5.0, y + 3 / 5.0, 0);
		glScalef(0.4, 0.2, 0.6);
		glColor3f(0, 0, 0);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
}

void enemy::drawEnemy5B() {
	// left side
	glPushMatrix();
		glTranslatef(x - 8 / 5.0, y + 1 / 5.0, 0);
		glScalef(0.2, 0.4, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 6 / 5.0, y + 3 / 5.0, 0);
		glScalef(0.2, 0.6, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 6 / 5.0, y - 5 / 5.0, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 3 / 5.0, y + 6 / 5.0, 0);
		glScalef(0.4, 0.4, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 3 / 5.0, y - 8 / 5.0, 0);
		glScalef(0.4, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 4 / 5.0, y + 1 / 5.0, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 4 / 5.0, y - 3 / 5.0, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x - 2 / 5.0, y, 0);
		glScalef(0.2, 0.4, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	
	// body
	glPushMatrix();
		glTranslatef(x, y + 1.5 / 5.0, 0);
		glScalef(0.2, 1.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	
	// right side
	glPushMatrix();
		glTranslatef(x + 8 / 5.0, y + 1 / 5.0, 0);
		glScalef(0.2, 0.4, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 6 / 5.0, y + 3 / 5.0, 0);
		glScalef(0.2, 0.6, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 6 / 5.0, y - 5 / 5.0, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 3 / 5.0, y + 6 / 5.0, 0);
		glScalef(0.4, 0.4, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 3 / 5.0, y - 8 / 5.0, 0);
		glScalef(0.4, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 4 / 5.0, y + 1 / 5.0, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 4 / 5.0, y - 3 / 5.0, 0);
		glScalef(0.2, 0.2, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 2 / 5.0, y, 0);
		glScalef(0.2, 0.4, 0.6);
		glColor3f(c.r, c.g, c.b);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	
	// Eyes
	glPushMatrix();
		glTranslatef(x - 3 / 5.0, y + 3 / 5.0, 0);
		glScalef(0.4, 0.2, 0.6);
		glColor3f(0, 0, 0);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(x + 3 / 5.0, y + 3 / 5.0, 0);
		glScalef(0.4, 0.2, 0.6);
		glColor3f(0, 0, 0);
		glScalef(scale, scale, scale); draw::cube();
	glPopMatrix();
}