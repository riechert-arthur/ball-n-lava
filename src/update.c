#include "update.h"

void update(void) {
 
  elapseTime(state);
  updatePosition(0.0f, 0.0f, ball->entity, state, 100.0f);
  updatePosition(0.0f, 0.0f, platform->entity, state, 0.0f);
  glutPostRedisplay();

  return;

}
