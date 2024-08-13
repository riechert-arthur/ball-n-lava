#ifndef BALL_H
#define BALL_H

#include "physics.h"

typedef struct ball {
  EntityProperties* entity;
  float r;
  float red;
  float green;
  float blue;
} Ball;

#endif
