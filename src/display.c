#include "display.h"

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

  return;

}
