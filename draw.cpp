#include "draw.hpp"

void draw::cube()
{
	glBegin(GL_QUADS);
		// draw front face
        glNormal3f(0, 0, 1);
		glVertex3f(-1.0, -1.0, 1.0);
        glVertex3f( 1.0, -1.0, 1.0);
        glVertex3f( 1.0,  1.0, 1.0);
        glVertex3f(-1.0,  1.0, 1.0);
    glEnd();

    glBegin(GL_QUADS);
		// draw back face
        glNormal3f(0, 0, -1);
		glVertex3f( 1.0, -1.0, -1.0);
		glVertex3f(-1.0, -1.0, -1.0);
		glVertex3f(-1.0,  1.0, -1.0);
		glVertex3f( 1.0,  1.0, -1.0);
    glEnd();

    glBegin(GL_QUADS);
		// draw left face
		glNormal3f(-1, 0, 0);
        glVertex3f(-1.0, -1.0, -1.0);
		glVertex3f(-1.0, -1.0,  1.0);
		glVertex3f(-1.0,  1.0,  1.0);
		glVertex3f(-1.0,  1.0, -1.0);
    glEnd();

    glBegin(GL_QUADS);
		// draw right face
        glNormal3f(1, 0, 0);
		glVertex3f( 1.0, -1.0,  1.0);
		glVertex3f( 1.0, -1.0, -1.0);
		glVertex3f( 1.0,  1.0, -1.0);
		glVertex3f( 1.0,  1.0,  1.0);
    glEnd();
    glBegin(GL_QUADS);
		// draw top
        glNormal3f(0, 1, 0);
		glVertex3f(-1.0,  1.0,  1.0);
		glVertex3f( 1.0,  1.0,  1.0);
		glVertex3f( 1.0,  1.0, -1.0);
		glVertex3f(-1.0,  1.0, -1.0);
    glEnd();
    glBegin(GL_QUADS);
		// draw bottom
        glNormal3f(0, -1, 0);
		glVertex3f(-1.0, -1.0, -1.0);
		glVertex3f( 1.0, -1.0, -1.0);
		glVertex3f( 1.0, -1.0,  1.0);
		glVertex3f(-1.0, -1.0,  1.0);
    glEnd();
}

void draw::cylinder(float r, float zDepth){
    GLUquadricObj *quadratic;
    quadratic = gluNewQuadric();
    gluCylinder(quadratic, r, r, zDepth, 7, 7);
}

void draw::sphere(float r){
    GLUquadricObj *quadratic;
    quadratic = gluNewQuadric();
    gluSphere(quadratic, r , 12, 12);
}

void draw::text(const unsigned char* string){
    glutStrokeString(GLUT_STROKE_ROMAN, string);
}