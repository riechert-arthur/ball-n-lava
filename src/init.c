#include "init.h"

void initGame(void) {
 
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

  glutInitWindowSize(1366, 768);
  glutInitWindowPosition(0, 0);

  glutCreateWindow("Circle Drawing");

  glClearColor(0.0, 0.0, 0.0, 1.0);
  glColor3f(0.0, 1.0, 0.0);

  glPointSize(1.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  gluOrtho2D(LEFT_BORDER, RIGHT_BORDER, BOTTOM_BORDER, TOP_BORDER);

  return;

}
