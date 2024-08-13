#ifndef PHYSICS_H
#define PHYSICS_H

#include <time.h>
#include <math.h>

#define G 9.81

typedef struct { 
  clock_t lastUpdate; 
  float elapsedTime;
  float delta;
} State;

typedef struct {
  float mass; 
  float x;
  float y;
  float vX;
  float vY;
} EntityProperties; 

void elapseTime(State*);
void updatePosition(float, float, EntityProperties*, State*, float);

#endif
