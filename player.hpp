#ifndef _PLAYER_
#define _PLAYER_

#include "ship.hpp"

class player:public ship{
public:
    player();
    
    virtual void draw();
};

#endif