#ifndef ENTITIES_H
#define ENTITIES_H

#include <stdlib.h>

#include "ball.h"
#include "platform.h"
#include "physics.h" 

Ball* initBall(float, float, float, float, float, float, float);
Platform* initPlatform(float, float, float, float, float, float, float, float);

#endif
