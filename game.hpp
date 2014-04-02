#ifndef _GAME_
#define _GAME_

#ifdef _WIN32
#include <windows.h>
#endif

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <glui.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cstdlib>
#include <math.h>

#include "timer.h"
#include "vector.h"

#include "draw.hpp"
#include "bullet.hpp"
#include "player.hpp"
#include "enemy.hpp"
#include "particle.hpp"

//Main game class.
//Holds all game logic.
class game{
public:
    // Window settings
    int windowID;				// Glut window ID (for display)
    int Win[2];					// window (x,y) size

    //The player.
    player p;

    //Game score.
    int score;
    //Game level.
    int level;

    //Size of enemies array.
    int enemiesSize;
    //Game enemies.
    enemy** enemies;

    //Size of bullets array.
    int bulletsSize;
    //Bullets.
    bullet** bullets;

    //Size of particles array.
    int particlesSize;
    //Particles
    particle** particles;

    //Is left key being pressed.
    bool leftDown;
    //Is right key being pressed.
    bool rightDown;
    //Is shooting key being pressed.
    bool shootDown;
    //Shooting cooldown timer.
    Timer shootTimer;

    //Camera settings
    float ZOOM_SCALE;

    GLdouble camXPos;
    GLdouble camYPos;
    GLdouble camZPos;

    GLdouble CAMERA_FOVY;
    GLdouble NEAR_CLIP;
    GLdouble FAR_CLIP;

    // Render settings
    enum { WIREFRAME, POINT, SOLID, OUTLINED, SHINY, MATTE };
    int renderStyle;

    enum { START, GAME, LEVEL, GAME_OVER };
    int screen;

    //Timers
    Timer sceneTimer;
    Timer updateTimer;
    Timer frameRateTimer;
    Timer lightTimer;

    //Singleton accessor to game.
    static game* instance;


    game();

    void run();

    void setScreen(int s);
    void setLevel(int l);
    void update();
    void draw();

    static void reshape(int w, int h);
    static void display(void);

    static void keyboardUp(unsigned char key, int x, int y);
    static void keyboardDown(unsigned char key, int x, int y);
};

#endif