#ifndef _DRAW_
#define _DRAW_

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>

//Drawing handler.
class draw{
public:    
    //Draw unit cube.
    static void cube();

    //Draw cylinder.
    //r radius of cylinder.
    //zDepth depth.
    static void cylinder(float r, float zDepth);

    //Draw sphere.
    //r radius.
    static void sphere(float r);

    //Draw text
    //string to draw.
    static void text(const unsigned char* string);
};

#endif