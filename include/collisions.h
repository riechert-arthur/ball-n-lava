#ifndef COLLISIONS_H
#define COLLISIONS_H

#include "ball.h"
#include "platform.h"

#define MAX_ENTITIES 20 

#define RECTANGLE 1
#define CIRCLE 2

typedef union {
  Platform p;
  Ball b;
} Object;

typedef struct { 
  Object* obj;
  int type;
} CollisionObject;

#endif
