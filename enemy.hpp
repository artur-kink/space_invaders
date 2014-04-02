#ifndef _ENEMY_
#define _ENEMY_

#include "ship.hpp"
#include "timer.h"
#include "color.hpp"

class enemy:public ship{
public:

	Timer animationTimer;
    Timer deathTimer;
	bool frame;

    float dir;
    int type;

    //Enemy color.
    color c;

    bool beenHit;
    float scale;

    float velocity;

    enemy();
    enemy(float x, float y, int t, int level);

    void update();
    void drawEnemy0();
    void drawEnemy1();
    void drawEnemy2();
    void drawEnemy3();
    void drawEnemy4();
    void drawEnemy5();
    void drawEnemy6();
    
    void drawEnemy0B();
    void drawEnemy1B();
    void drawEnemy2B();
    void drawEnemy3B();
    void drawEnemy4B();
    void drawEnemy5B();
    void drawEnemy6B();
    virtual void draw();

    void hit();
};

#endif
