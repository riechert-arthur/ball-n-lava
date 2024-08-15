#include "main.h"

State* state; 
Platform* platform;
Ball* ball;

void myInit() {
  
  glClearColor(0.0, 0.0, 0.0, 1.0);
  glColor3f(0.0, 1.0, 0.0);

  glPointSize(1.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  gluOrtho2D(LEFT_BORDER, RIGHT_BORDER, BOTTOM_BORDER, TOP_BORDER);

}

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
}

void display(void) {

  glClear(GL_COLOR_BUFFER_BIT);
  
  drawCircle(
    ball->entity->x,
    ball->entity->y,
    ball->r,
    ball->red,
    ball->green,
    ball->blue
  );

  drawRectangle(
    platform->entity->x,
    platform->entity->y,
    platform->w,
    platform->h,
    platform->red,
    platform->green,
    platform->blue
  );

  glFlush();

}

void update(void) {
 
  elapseTime(state);
  updatePosition(0.0f, 0.0f, ball->entity, state, 100.0f);
  updatePosition(0.0f, 0.0f, platform->entity, state, 0.0f);
  glutPostRedisplay();

}

int main(int argc, char** argv) {

  if (!(state = (State*) malloc(sizeof(State)))) {
    free(state);
  }

  state->lastUpdate = 0;
  state->elapsedTime = 0.0f;
  state->delta = 0.0f;

  ball = initBall(10.0f, 0.0f, 0.0f, 100.0f, 1.0f, 0.0f, 0.0f);
  platform = initPlatform(1000.0f, 0.0f, 0.0f, 300.0f, 100.0f, 0.0f, 1.0f, 0.0f);

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

  glutInitWindowSize(1366, 768);
  glutInitWindowPosition(0, 0);

  glutCreateWindow("Circle Drawing");
  myInit();

  glutKeyboardFunc(handleKeypress);
  glutDisplayFunc(display);
  glutIdleFunc(update);
  glutMainLoop();

}
