#ifndef _COLOR_
#define _COLOR_

class color{
public:
    float r, g, b;

    color();
    color(float r, float g, float b);
    color(const color& c);
};

static color white(1.0, 1.0, 1.0);
static color magenta(1.0, 0, 1.0);
static color blue(0.0, 42.0/255.0, 1.0);
static color teal(0.0, 195.0/255.0, 1.0);
static color green(0.0, 1.0, 55.0/255.0);
static color lime(155.0/255.0, 1.0, 0.0);
static color yellow(1.0, 1.0, 0.0);
static color brown(1.0, 200.00/255.0, 0.0);
static color orange(1.0, 95.00/255.0, 0.0);
static color red(1.0, 0.0, 0.0);
static color purple(0.6, 0.0, 0.6);

#endif