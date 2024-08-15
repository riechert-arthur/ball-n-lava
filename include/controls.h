#ifndef CONTROLS_H 
#define CONTROLS_H

#include "entities.h"
#include "graphics.h"

extern State* state;
extern Ball* ball;
extern Platform* platform;

void handleKeypress(unsigned char, int, int);

#endif
