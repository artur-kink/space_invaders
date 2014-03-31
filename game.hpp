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
#include <math.h>

#include "timer.h"
#include "vector.h"

#include "draw.hpp"
#include "bullet.hpp"
#include "player.hpp"
#include "enemy.hpp"


class game{
public:
    // Window settings
    int windowID;				// Glut window ID (for display)
    int Win[2];					// window (x,y) size

    player p;
    
    int enemiesSize;
    enemy** enemies;

    int bulletsSize;
    bullet** bullets;

    bool leftDown;
    bool rightDown;
    bool shootDown;
    Timer shootTimer;

    // Camera settings
    float ZOOM_SCALE;

    GLdouble camXPos;
    GLdouble camYPos;
    GLdouble camZPos;

    GLdouble CAMERA_FOVY;
    GLdouble NEAR_CLIP;
    GLdouble FAR_CLIP;

    // Render settings
    enum { WIREFRAME, POINT, SOLID, OUTLINED, SHINY, MATTE };	// README: the different render styles
    int renderStyle;			// README: the selected render style

    // Time settings
    Timer* updateTimer;
    Timer* frameRateTimer;

    static game* instance;

    // Callbacks for handling events in glut
    static void reshape(int w, int h);
    static void idle(void);
    static void display(void);

    static void keyboardUp(unsigned char key, int x, int y);
    static void keyboardDown(unsigned char key, int x, int y);

    game();
    void run();

    void update();
    void draw();
};

#endif