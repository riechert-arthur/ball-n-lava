#include "graphics.h"

void drawCircle(
  float xOffset,
  float yOffset,
  float r,
  float red,
  float green,
  float blue
) {
  
  glBegin(GL_TRIANGLE_FAN);
  glColor3f(red, green, blue);
  glVertex2f(xOffset, yOffset);

  float x, y, i;

  for (i = 0; i <= NUM_SEGMENTS; i++) {

    float theta = 2.0f * PI * (float) i / (float) NUM_SEGMENTS;
    x = r * cos(theta) + xOffset;
    y = r * sin(theta) + yOffset;

    glVertex2i(x,y);

  }

  glColor3f(0.0f, 0.0f, 0.0f);
  glEnd();

  return;

}

void drawRectangle(
  float xOffset,
  float yOffset,
  float w,
  float h,
  float red,
  float green,
  float blue
) {

  glBegin(GL_POLYGON);
  glColor3f(red, green, blue);

  glVertex2f(xOffset, yOffset);
  glVertex2f(xOffset + w, yOffset);
  glVertex2f(xOffset + w, yOffset - h);
  glVertex2f(xOffset, yOffset - h);

  glColor3f(0.0f, 0.0f, 0.0f);
  glEnd();

  return;

}
