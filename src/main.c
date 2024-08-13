#include "main.h"

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
  
  drawCircle(100, -200, 200);

  glFlush();

}

void update(void) {
  
  glutPostRedisplay();

}

int main(int argc, char** argv) {

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

  glutInitWindowSize(1366, 768);
  glutInitWindowPosition(0, 0);

  glutCreateWindow("Circle Drawing");
  myInit();

  glutDisplayFunc(display);
  glutIdleFunc(display);
  glutMainLoop();

}
