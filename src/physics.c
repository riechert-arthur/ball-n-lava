#include "physics.h"

void elapseTime(State* state) {
  
  clock_t capture = clock(); 
  float delta = (float) (capture - state->lastUpdate) / CLOCKS_PER_SEC;

  state->elapsedTime += delta;
  state->lastUpdate = capture;
  state->delta = delta;

  return;

}

void updatePosition(
  float dVX,
  float dVY,
  EntityProperties* entity,
  State* state,
  float gMultiplier
) {
 
  entity->vX += dVX;
  entity->vY += dVY - G * gMultiplier * state->delta;

  entity->x += entity->vX * state->delta;
  entity->y += entity->vY * state->delta + 0.5 * -G * gMultiplier * powf(state->delta, 2.0f);

  return;

}

void applyForce(
  float fX,
  float fY,
  EntityProperties* entity,
  State* state,
  float fMultiplier,
  float gMultiplier
) {

  if (entity->mass == 0.0f) {
    return;
  }

  float dVX = fX * fMultiplier / entity->mass;
  float dVY = fY * fMultiplier / entity->mass;

  updatePosition(dVX, dVY, entity, state, gMultiplier);

  return;

}
