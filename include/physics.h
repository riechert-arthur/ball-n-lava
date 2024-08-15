#ifndef PHYSICS_H
#define PHYSICS_H

#include <time.h>
#include <math.h>

#define G 9.81

#define LEFT_BORDER -780
#define RIGHT_BORDER 780
#define TOP_BORDER 420
#define BOTTOM_BORDER -420

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
void applyForce(float, float, EntityProperties*, State*, float, float);

#endif
