#include "main.h"

State* state; 
Ball* ball;

void myInit() {
  
  glClearColor(0.0, 0.0, 0.0, 1.0);
  glColor3f(0.0, 1.0, 0.0);

  glPointSize(1.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  gluOrtho2D(-780, 780, -420, 420);

}

void display(void) {

  glClear(GL_COLOR_BUFFER_BIT);
  
  drawCircle(ball->x, ball->y, ball->r);
  drawCircle(100.0f, -100.0f, 10.0f);

  glFlush();

}

void update(void) {
 
  elapseTime(state);
  updatePosition(0.0f, 0.0f, ball, state);
  glutPostRedisplay();

}

int main(int argc, char** argv) {

  if (!(state = (State*) malloc(sizeof(State)))) {
    free(state);
  }

  state->lastUpdate = 0;
  state->elapsedTime = 0.0f;
  state->delta = 0.0f;

  if (!(ball = (Ball*) malloc(sizeof(Ball)))) {
    free(ball);
  }

  ball->mass = 10.0f;
  ball->x = 0.0f;
  ball->y = 0.0f;
  ball->r = 100.0f;
  ball->vX = 0.0f;
  ball->vY = 0.0f;

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

  glutInitWindowSize(1366, 768);
  glutInitWindowPosition(0, 0);

  glutCreateWindow("Circle Drawing");
  myInit();

  glutDisplayFunc(display);
  glutIdleFunc(update);
  glutMainLoop();

}
