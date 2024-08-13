#include "main.h"

State* state; 
Ball* ball;
Platform* platform;

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
  updatePosition(0.0f, 0.0f, ball->entity, state, 10.0f);
  updatePosition(0.0f, 0.0f, platform->entity, state, 1.0f);
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

  if (!(ball->entity = (EntityProperties*) malloc(sizeof(EntityProperties)))) {
    free(ball->entity);
    free(ball);
  }

  ball->entity->mass = 10.0f;
  ball->entity->x = 0.0f;
  ball->entity->y = 0.0f;
  ball->r = 100.0f;
  ball->entity->vX = 0.0f;
  ball->entity->vY = 0.0f;
  ball->red = 1.0f;
  ball->green = 0.0f;
  ball->blue = 0.0f;

  if (!(platform = (Platform*) malloc(sizeof(Platform)))) {
    free(platform);
  }

  if (!(platform->entity = (EntityProperties*) malloc(sizeof(EntityProperties)))) {
    free(ball->entity);
    free(ball);
  }

  platform->entity->mass = 10.0f;
  platform->entity->x = 0.0f;
  platform->entity->y = -100.0f;
  platform->w = 500.0f;
  platform->h = 50.0f;
  platform->entity->vX = 0.0f;
  platform->entity->vY = 0.0f;
  platform->red = 0.0f;
  platform->green = 1.0f;
  platform->blue = 0.0f;

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
