#ifndef _PLAYER_
#define _PLAYER_

#include "ship.hpp"

//Player class.
class player:public ship{
public:
    player();
    
    virtual void draw();
};

#endif