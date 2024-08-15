#include "controls.h"

void handleKeypress(unsigned char key, int x, int y) {

  switch (key) {

    case 27:
      exit(0);

    case 'a':
      applyForce(500.0f, 0.0f, platform->entity, state, -10.0f, 0.0f);  
      break;

    case 'd':
      applyForce(500.0f, 0.0f, platform->entity, state, 10.0f, 0.0f);  
      break;

  }

  return;

}
