#include "physics.h"

void elapseTime(State* state) {
  
  clock_t capture = clock(); 
  float delta = (float) (capture - state->lastUpdate) / CLOCKS_PER_SEC;

  state->elapsedTime += delta;
  state->lastUpdate = capture;
  state->delta = delta;

  return;

}

void updatePosition(float dVX, float dVY, Ball* entity, State* state) {
 
  /**
  * Only accounts for gravity so far.
  */
  
  entity->vX += dVX;
  entity->vY += dVY - G * state->delta;

  entity->x += entity->vX * state->delta;
  entity->y += entity->vY * state->delta + 0.5 * -G * powf(state->delta, 2.0f);

  return;

}
