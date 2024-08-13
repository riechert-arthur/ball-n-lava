#include "graphics.h"

void drawCircle(float xOffset, float yOffset, float r) {
  
  glBegin(GL_POINTS);

  float x, y, i;

  for (i = 0; i < (2 * PI); i += 0.001) {

    x = r * cos(i) + xOffset;
    y = r * sin(i) + yOffset;

    glVertex2i(x,y);

  }

  glEnd();

}
