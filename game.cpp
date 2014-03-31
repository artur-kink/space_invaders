#include "game.hpp"

game* game::instance = 0;

game::game(){
    instance = this;
    
    updateTimer = new Timer();
	frameRateTimer = new Timer();

    // Process program arguments
    Win[0] = 640;
    Win[1] = 480;

    renderStyle = WIREFRAME;

    ZOOM_SCALE = 1;

    camXPos =  0.0;
    camYPos =  0.0;
    camZPos = -50.0;

    CAMERA_FOVY = 60.0;
    NEAR_CLIP   = 0.1;
    FAR_CLIP    = 1000.0;

    leftDown = false;
    rightDown = false;
    shootDown = false;
    shootTimer.reset();

    bulletsSize = 15;
    bullets = new bullet*[bulletsSize];
    memset(bullets, 0, sizeof(bullet*)*bulletsSize);

    enemiesSize = 20;
    enemies = new enemy*[enemiesSize];

    for(int i = 0; i < enemiesSize; i++){
        enemies[i] = new enemy();
        // insert math here to space out new enemies
        enemies[i]->x = (i*6)%60;
        enemies[i]->y = 30 + ((i*6)/60)*3;
    }

    int argc = 0;
    glutInit(&argc, 0);
    // Set video mode: double-buffered, color, depth-buffered
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    // Create window
    glutInitWindowPosition (0, 0);
    glutInitWindowSize(Win[0],Win[1]);
    windowID = glutCreateWindow("Space Invaders");


    GLUI_Master.set_glutIdleFunc(display);

    // Setup callback functions to handle events
    glutReshapeFunc(reshape);	// Call reshape whenever window resized
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboardDown);
    glutKeyboardUpFunc(keyboardUp);

    glClearColor(0.0f,0.0f,0.0f,1.0f);
}

void game::run(){
    // Invoke the standard GLUT main event loop
    glutMainLoop();
}

// Handles the window being resized by updating the viewport
// and projection matrices
void game::reshape(int w, int h)
{
	// Update internal variables and OpenGL viewport
	instance->Win[0] = w;
	instance->Win[1] = h;
	glViewport(0, 0, (GLsizei)instance->Win[0], (GLsizei)instance->Win[1]);

    // Setup projection matrix for new window
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
	gluPerspective(instance->CAMERA_FOVY,
       (GLdouble)instance->Win[0]/(GLdouble)instance->Win[1], instance->NEAR_CLIP, instance->FAR_CLIP);
}

// display callback
void game::display(void)
{
    //Draw and update 60 frames a second.
    if(instance->frameRateTimer->elapsed() > 1.0/60.0){
        instance->frameRateTimer->reset();
        instance->update();
        instance->draw();
    }
}

void game::update(){

    if(leftDown && p.x > -37)
        p.x -= 1.0f;
    if(rightDown && p.x < 37)
        p.x += 1.0f;

    if(shootDown && shootTimer.elapsed() > 1.0/30.0){
        shootTimer.reset();
        for(int i = 0; i < bulletsSize; i++){
            if(bullets[i] == 0){
                bullets[i] = new bullet(p.x, p.y, 1);
                break;
            }
        }
    }

    for(int i = 0; i < enemiesSize; i++){
        if(enemies[i]){
            enemies[i]->update();
        }
    }

    for(int i = 0; i < bulletsSize; i++){
        if(bullets[i]){
            
            bullets[i]->update();
            if(bullets[i]->destroy){
                delete bullets[i];
                bullets[i] = 0;
                continue;
            }
            
            for(int j = 0; j < enemiesSize; j++){
                if(enemies[j]){
                    if(bullets[i]->x < enemies[j]->x + 1 && bullets[i]->x > enemies[j]->x &&
                        bullets[i]->y < enemies[j]->y + 1 && bullets[i]->y > enemies[j]->y ||
                        bullets[i]->x + 0.3 < enemies[j]->x + 1 && bullets[i]->x + 0.3 > enemies[j]->x &&
                        bullets[i]->y + 0.3 < enemies[j]->y + 1 && bullets[i]->y + 0.3 > enemies[j]->y){
                        delete enemies[j];
                        enemies[j] = 0;

                        delete bullets[i];
                        bullets[i] = 0;

                        break;
                    }
                }
            }
        }
    }

}

void game::draw(){

    //Reset draw settings.
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
    glDisable(GL_COLOR_MATERIAL);
    GLfloat blank[] = {0, 0, 0};
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, blank);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, blank);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, blank);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, blank);
    glShadeModel(GL_SMOOTH);

    //Setup lighting for shiny and matte.
    if(renderStyle == SHINY){
        glEnable(GL_LIGHTING);
        glEnable(GL_LIGHT0);

        //Setup material and light values.
        GLfloat specular[] = {0.5, 0.5, 0.5};
        GLfloat ambient[] = {0.2, 0.2, 0.2};
        GLfloat diffuse[] = {0.5, 0.5, 0.5};
        GLfloat mspecular[] = { 0.2, 0.2, 0.2, 0.2 };
        GLfloat mat_shininess[] = {0.4};

        GLfloat light_position[] = { 15*cos((0/180)*3.14),
            0,  15*sin((0/180)*3.14), 0.0 };

        //Set materials and lights
        glMaterialfv(GL_FRONT, GL_SPECULAR, mspecular);
        glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
        glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
        glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
        glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
        glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
        glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    }else if(renderStyle == MATTE){
        glEnable(GL_LIGHTING);
        glEnable(GL_LIGHT0);

        //Setup material and light values.
        GLfloat specular[] = {0.0, 0.0, 0.0};
        GLfloat ambient[] = {0, 0, 0};
        GLfloat diffuse[] = {0.5, 0.5, 0.5};
        GLfloat mspecular[] = { 0, 0, 0, 0 };
        GLfloat mat_shininess[] = {0};

        GLfloat light_position[] = { 15*cos((0/180)*3.14),
            0,  15*sin((0/180)*3.14), 0.0 };

        //Set materials and lights
        glMaterialfv(GL_FRONT, GL_SPECULAR, mspecular);
        glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
        glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
        glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
        glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
        glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
        glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
        glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    }

    // Clear the screen with the background colour
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Setup the model-view transformation matrix
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

	// Specify camera transformation
	glTranslatef(camXPos, camYPos, camZPos);
    glScalef(ZOOM_SCALE, ZOOM_SCALE, ZOOM_SCALE);

    if(renderStyle == WIREFRAME){
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    }else if(renderStyle == POINT){
        glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
    }else{
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }


	glPushMatrix();
        p.draw();
        for(int i = 0; i < enemiesSize; i++){
            if(enemies[i]){
                enemies[i]->draw();
            }
        }

        for(int i = 0; i < bulletsSize; i++){
            if(bullets[i]){
                bullets[i]->draw();
            }
        }
    glPopMatrix();

    // Execute any GL functions that are in the queue just to be safe
    glFlush();

    // Now, show the frame buffer that we just drew into.
    // (this prevents flickering).
    glutSwapBuffers();
}

void game::keyboardUp(unsigned char key, int x, int y){
    switch(key){
        case 'a':
            instance->leftDown = false;
            break;
        case 'd':
            instance->rightDown = false;
            break;
        case 'w':
            instance->shootDown = false;
            break;
    }
}

void game::keyboardDown(unsigned char key, int x, int y){
    switch(key){
        case 'a':
            instance->leftDown = true;
            break;
        case 'd':
            instance->rightDown = true;
            break;
        case 'w':
            instance->shootDown = true;
            break;
    }
}
