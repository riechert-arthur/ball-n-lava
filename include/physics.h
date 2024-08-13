#ifndef PHYSICS_H
#define PHYSICS_H

#include <time.h>
#include <math.h>
#include <ball.h>

#define G 1000.00

typedef struct state {
  clock_t lastUpdate; 
  float elapsedTime;
  float delta;
} State;

void elapseTime(State*);
void updatePosition(float, float, Ball*, State*);

#endif
