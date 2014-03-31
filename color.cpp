#include "color.hpp"

color::color(){
    r = g = b = 0.0f;
}

color::color(float r, float g, float b){
    this->r = r;
    this->g = g;
    this->b = b;
}

color::color(const color& c){
    r = c.r;
    g = c.g;
    b = c.b;
}