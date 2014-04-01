#include "game.hpp"

game* game::instance = 0;

game::game(){
    instance = this;

    srand (time(NULL));

    updateTimer.reset();
	frameRateTimer.reset();

    // Process program arguments
    Win[0] = 800;
    Win[1] = 600;

    renderStyle = MATTE;

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

    particlesSize = 200;
    particles = new particle*[particlesSize];
    memset(particles, 0, sizeof(particle*)*particlesSize);

    bulletsSize = 55;
    bullets = new bullet*[bulletsSize];
    memset(bullets, 0, sizeof(bullet*)*bulletsSize);

    enemiesSize = 105;
    enemies = new enemy*[enemiesSize];

    for(int i = 0; i < enemiesSize; i++){
        enemies[i] = new enemy(-37 + (i*6)%70, 10 + ((i*6)/70)*3, ((i*6)/70)%3);
        
        if(((i*6)/70)%2 == 1)
            enemies[i]->dir = -1;
        
        if(((i*6)/70) == 1){
            enemies[i]->c = blue;
        }else if(((i*6)/70) == 2){
            enemies[i]->c = teal;
        }else if(((i*6)/70) == 3){
            enemies[i]->c = green;
        }else if(((i*6)/70) == 4){
            enemies[i]->c = lime;
        }else if(((i*6)/70) == 5){
            enemies[i]->c = yellow;
        }else if(((i*6)/70) == 6){
            enemies[i]->c = brown;
        }else if(((i*6)/70) == 7){
            enemies[i]->c = orange;
        }else if(((i*6)/70) == 8){
            enemies[i]->c = red;
        }
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
    //Start glut main loop.
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
    //Draw and update 60 times a second.
    if(instance->frameRateTimer.elapsed() > 1.0/60.0){
        instance->frameRateTimer.reset();
        instance->update();
        instance->draw();
    }
}

void game::update(){

    //Update player position if moving.
    if(leftDown && p.x > -37)
        p.x -= 1.0f;
    if(rightDown && p.x < 37)
        p.x += 1.0f;

    //Player shoot
    if(shootDown && shootTimer.elapsed() > 1.0/2.0){
        shootTimer.reset();
        for(int i = 0; i < bulletsSize; i++){
            if(bullets[i] == 0){
                bullets[i] = new bullet(p.x, p.y, 1);
                break;
            }
        }
    }

    //Update enemies.
    for(int i = 0; i < enemiesSize; i++){
        if(enemies[i]){
            enemies[i]->update();

            //Shoot
            if(rand()%1000 == 0){
                for(int b = 0; b < bulletsSize; b++){
                    if(bullets[b] == 0){
                        bullets[b] = new bullet(enemies[i]->x, enemies[i]->y, -1.0);
                        break;
                    }
                }
            }
        }
    }

    //Update bullets.
    for(int i = 0; i < bulletsSize; i++){
        if(bullets[i]){
            
            bullets[i]->update();
            //Destroy bullet if its off map.
            if(bullets[i]->destroy){
                delete bullets[i];
                bullets[i] = 0;
                continue;
            }

            //Get bullet coordinates in positive quadrant.
            float bx = (bullets[i]->x + 38);
            float by = (bullets[i]->y + 38);

            //Check for collision with bullets and enemies.
            if(bullets[i]->dir > 0){
                for(int j = 0; j < enemiesSize; j++){
                    if(enemies[j]){

                        //Get enemy coordinates in positive quadrant.
                        float ex1 = (enemies[j]->x - 2 + 38);
                        float ex2 = (enemies[j]->x + 2 + 38);
                        float ey1 = (enemies[j]->y - 2 + 38);
                        float ey2 = (enemies[j]->y + 2 + 38);

                        if(bx > ex1 && bx < ex2 && by > ey1 && by < ey2){
                            delete enemies[j];
                            enemies[j] = 0;

                            //Spawn explosion particles
                            int spawned = 0;
                            for(int p = 0; p < particlesSize; p++){
                                if(particles[p] == 0){
                                    particles[p] = new particle(bullets[i]->x, bullets[i]->y);
                                    spawned++;
                                    if(spawned > 10){
                                        break;
                                    }
                                }
                            }

                            bullets[i]->destroy = true;
                            break;
                        }
                    }
                }
            }else{
                //Check for collision with player.
                //Get enemy coordinates in positive quadrant.
                float px1 = (p.x - 1 + 38);
                float px2 = (p.x + 1 + 38);
                float py1 = (p.y - 1 + 38);
                float py2 = (p.y + 1 + 38);
                if(bx > px1 && bx < px2 && by > py1 && by < py2){
                    //Kill Player.

                    bullets[i]->destroy = true;
                }
            }
        }
    }

    for(int i = 0; i < particlesSize; i++){
        if(particles[i]){
            particles[i]->update();
            if(particles[i]->destroy){
                delete particles[i];
                particles[i] = 0;
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

        GLfloat light_position[] = { p.x,
            0,  p.y, 0.0 };

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
        glEnable(GL_COLOR_MATERIAL);
        glEnable(GL_LIGHTING);
        glEnable(GL_LIGHT0);

        //Setup material and light values.
        GLfloat specular[] = {0.0, 0.0, 0.0};
        GLfloat ambient[] = {0, 0, 0};
        GLfloat diffuse[] = {0.3, 0.3, 0.3};
        GLfloat mspecular[] = { 0, 0, 0, 0 };
        GLfloat mat_shininess[] = {0};

        GLfloat light_position[] = { p.x,
            p.y, 10, 0 };

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

        glPushMatrix();
        glColor3f(1.0f, 1.0f, 0);
        glScalef(0.1f, 0.1f, 0.1f);
        draw::text((unsigned char*)"test");
        glPopMatrix();
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

        for(int i = 0; i < particlesSize; i++){
            if(particles[i]){
                particles[i]->draw();
            }
        }
    glPopMatrix();
    
    glFlush();
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
