#ifndef _DRAW_
#define _DRAW_

#include <GL/gl.h>
#include <GL/glu.h>

class draw{
public:    
    // Draw a unit cube, centered at the current location
    static void cube();

    //Draw cylinder with given radius r and length in z.
    static void cylinder(float r, float zDepth);

    static void sphere(float r);
};

#endif