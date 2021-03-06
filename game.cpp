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
    screen = START;

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

    score = 0;
    level = 0;

    //Initialize particles.
    particlesSize = 100;
    particles = new particle*[particlesSize];
    memset(particles, 0, sizeof(particle*)*particlesSize);

    //Initialize bullets.
    bulletsSize = 55;
    bullets = new bullet*[bulletsSize];
    memset(bullets, 0, sizeof(bullet*)*bulletsSize);

    //Set beginning level.
    enemies = 0;
    setLevel(0);
    
    int argc = 0;
    glutInit(&argc, 0);
    //Set video mode: double-buffered, color, depth-buffered
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    //Create window
    glutInitWindowPosition (0, 0);
    glutInitWindowSize(Win[0],Win[1]);
    windowID = glutCreateWindow("Space Invaders");


    GLUI_Master.set_glutIdleFunc(display);

    //Setup callback functions to handle events
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboardDown);
    glutKeyboardUpFunc(keyboardUp);
}

void game::run(){
    //Start glut loop.
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

//Display callback.
void game::display(void)
{
    //Draw and update game 60 times a second.
    if(instance->frameRateTimer.elapsed() > 1.0/60.0){
        instance->frameRateTimer.reset();
        instance->update();
        instance->draw();
    }
}

//Game state update.
void game::update(){

    if(screen == START){
        //Nothing special for start.
    }else if(screen == GAME){
        //Update player position if moving.
        if(leftDown && p.x > -37)
            p.x -= 1.0f;
        if(rightDown && p.x < 37)
            p.x += 1.0f;

        //Player shoot
        if(shootDown && shootTimer.elapsed() > 1.0/2.5){
            for(int i = 0; i < bulletsSize; i++){
                if(bullets[i] == 0){
                    shootTimer.reset();
                    bullets[i] = new bullet(p.x, p.y, 1);
                    break;
                }
            }
        }


        bool allDead = true;
        //Update enemies.
        for(int i = 0; i < enemiesSize; i++){
            if(enemies[i]){
                allDead = false;
                enemies[i]->update();

                //Check if enemy reached bottom of screen
                if(enemies[i]->y <= p.y + p.h)
                    setScreen(GAME_OVER);

                //Shoot based on random probability
                if((float)rand()/(float)0xFFFFFFFF <= 0.0002 + 0.0001*(level+1)){
                    for(int b = 0; b < bulletsSize; b++){
                        if(bullets[b] == 0){
                            bullets[b] = new bullet(enemies[i]->x, enemies[i]->y, -1.0);
                            break;
                        }
                    }
                }
            }
        }

        //If all enemies dead move to next level.
        if(allDead){
            setLevel(level+1);
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
                            float ex1 = (enemies[j]->x - enemies[j]->w + 38);
                            float ex2 = (enemies[j]->x + enemies[j]->w  + 38);
                            float ey1 = (enemies[j]->y - enemies[j]->h  + 38);
                            float ey2 = (enemies[j]->y + enemies[j]->h  + 38);

                            if(bx > ex1 && bx < ex2 && by > ey1 && by < ey2){
                                enemies[j]->hit();
                                score += 10;

                                bullets[i]->destroy = true;
                                break;
                            }
                        }
                    }
                }else{
                    //Check for collision with player.
                    //Get enemy coordinates in positive quadrant.
                    float px1 = (p.x - p.w + 38);
                    float px2 = (p.x + p.w + 38);
                    float py1 = (p.y - p.h + 38);
                    float py2 = (p.y + p.h + 38);
                    if(bx > px1 && bx < px2 && by > py1 && by < py2){
                        //Kill Player.
                        setScreen(GAME_OVER);

                        //Spawn explosion particles
                        int spawned = 0;
                        for(int p = 0; p < particlesSize; p++){
                            if(particles[p] == 0){
                                particles[p] = new particle(bullets[i]->x, bullets[i]->y);
                                spawned++;
                                if(spawned > 30){
                                    break;
                                }
                            }
                        }

                        bullets[i]->destroy = true;
                    }
                }
            }
        }
    }

    //Process any enemy deaths.
    for(int i = 0; i < enemiesSize; i++){
        if(enemies[i]){
            if(enemies[i]->beenHit && enemies[i]->deathTimer.elapsed() > 0.15){
                //Spawn explosion particles
                int spawned = 0;
                for(int p = 0; p < particlesSize; p++){
                    if(particles[p] == 0){
                        particles[p] = new particle(enemies[i]->x, enemies[i]->y);
                        spawned++;
                        if(spawned > 10){
                            break;
                        }
                    }
                }

                delete enemies[i];
                enemies[i] = 0;

                continue;
            }
        }
    }

    //Update particles.
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

//Set game screen.
void game::setScreen(int s){
    if(sceneTimer.elapsed() > 0.5){
        screen = s;
        sceneTimer.reset();
    }
}

//Set game level.
void game::setLevel(int l){
    level = l;

    if(level != 0){
        setScreen(LEVEL);
    }else{
        score = 0;
    }

    //Destroy all levels.
    for(int i = 0; i < bulletsSize; i++){
        if(bullets[i]){
            delete bullets[i];
            bullets[i] = 0;
        }
    }

    //Initialize enemies.
    enemiesSize = 70 + l*10;
    if(enemies){
        delete enemies;
    }
    
    enemies = new enemy*[enemiesSize];

    for(int i = 0; i < enemiesSize; i++){
        enemies[i] = new enemy(-32 + (i*7)%70, 10 + ((i*7)/70)*3, ((i*7)/70)%6, level);

        if(((i*7)/70)%2 == 1)
            enemies[i]->dir = -1;

        //Set enemy colors based on row.
        if(((i*7)/70)%10 == 1){
            enemies[i]->c = blue;
        }else if(((i*7)/70)%10 == 2){
            enemies[i]->c = teal;
        }else if(((i*7)/70)%9 == 3){
            enemies[i]->c = green;
        }else if(((i*7)/70)%10 == 4){
            enemies[i]->c = lime;
        }else if(((i*7)/70)%10 == 5){
            enemies[i]->c = yellow;
        }else if(((i*7)/70)%10 == 6){
            enemies[i]->c = brown;
        }else if(((i*7)/70)%10 == 7){
            enemies[i]->c = orange;
        }else if(((i*7)/70)%10 == 8){
            enemies[i]->c = red;
        }else if(((i*7)/70)%10 == 9){
            enemies[i]->c = purple;
        }
    }
}

//Draw game state.
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
        //Draw player.
        if(screen != GAME_OVER){
            p.draw();
        }

        //Draw enemies.
        for(int i = 0; i < enemiesSize; i++){
            if(enemies[i]){
                enemies[i]->draw();
            }
        }

        //Draw bullets.
        for(int i = 0; i < bulletsSize; i++){
            if(bullets[i]){
                bullets[i]->draw();
            }
        }

        //Draw particles.
        for(int i = 0; i < particlesSize; i++){
            if(particles[i]){
                particles[i]->draw();
            }
        }
    glPopMatrix();


    //Disable lighting for text rendering.
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);
    glDisable(GL_COLOR_MATERIAL);

    if(screen == START){
    //Draw start game.
    glPushMatrix();
        glColor3f(1.0f, 1.0f, 1.0f);
        glTranslatef(-20, 0, 5);
        glScalef(0.04f, 0.04f, 0.04f);

        draw::text((unsigned char*)"START GAME");
    glPopMatrix();
    }else if(screen == GAME_OVER){
    //Draw game over.
    glPushMatrix();
        glColor3f(1.0f, 1.0f, 1.0f);
        glTranslatef(-19, 0, 5);
        glScalef(0.04f, 0.04f, 0.04f);

        draw::text((unsigned char*)"GAME OVER");
    glPopMatrix();
    }else if(screen == LEVEL){
    //Draw level number.
    glPushMatrix();
        glColor3f(1.0f, 1.0f, 1.0f);
        glTranslatef(-14, 0, 5);
        glScalef(0.04f, 0.04f, 0.04f);

        char levelText[100];
        levelText[0] = 0;
        sprintf(levelText, "Level %d", level+1);

        draw::text((unsigned char*)levelText);
    glPopMatrix();
    }

    //Draw score.
    if(screen == GAME || screen == LEVEL || screen == GAME_OVER){
    glPushMatrix();
        glColor3f(1.0f, 1.0f, 1.0f);
        glTranslatef(-34, 24, 5);
        glScalef(0.01f, 0.01f, 0.01f);

        char scoreText[100];
        scoreText[0] = 0;
        sprintf(scoreText, "Score: %d", score);

        draw::text((unsigned char*)scoreText);
    glPopMatrix();
    }

    glFlush();
    glutSwapBuffers();
}

//Keyboard key released handler.
void game::keyboardUp(unsigned char key, int x, int y){
    if(key == 'a'){
        instance->leftDown = false;
    }else if(key == 'd'){
        instance->rightDown = false;
    }else if(key == 'w' || key == ' '){
        instance->shootDown = false;
    }
}

//Keyboard key pressed handler.
void game::keyboardDown(unsigned char key, int x, int y){
    if(instance->screen == START){
        instance->setScreen(game::GAME);
    }else if(instance->screen == GAME_OVER){
        instance->setLevel(0);
        instance->setScreen(game::START);
    }else if(instance->screen == LEVEL){
        instance->setScreen(game::GAME);
    }else{
        if(key == 'a'){
            instance->leftDown = true;
        }else if(key == 'd'){
            instance->rightDown = true;
        }else if(key == 'w' || key == ' '){
            instance->shootDown = true;
        }
    }
}
