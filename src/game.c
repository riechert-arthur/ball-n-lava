#include "game.h"

State* state; 
Platform* platform;
Ball* ball;

void game(void) {

  state = initState();
  ball = initBall(10.0f, 0.0f, 0.0f, 100.0f, 1.0f, 0.0f, 0.0f);
  platform = initPlatform(1000.0f, 0.0f, 0.0f, 300.0f, 100.0f, 0.0f, 1.0f, 0.0f);

  glutKeyboardFunc(handleKeypress);
  glutDisplayFunc(display);
  glutIdleFunc(update);
  glutMainLoop();

}
