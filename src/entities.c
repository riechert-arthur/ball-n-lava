#include "entities.h"

Ball* initBall(
  float mass,
  float x,
  float y,
  float r,
  float red,
  float green,
  float blue
) {

  Ball* ball;
    
  if (!(ball = (Ball*) malloc(sizeof(Ball)))) {
    free(ball);
    return NULL;
  }

  if (!(ball->entity = (EntityProperties*) malloc(sizeof(EntityProperties)))) {
    free(ball->entity);
    free(ball);
    return NULL;
  }

  ball->entity->mass = mass; 
  ball->entity->x = x; 
  ball->entity->y = y; 
  ball->r = r; 
  ball->entity->vX = 0.0f; 
  ball->entity->vY = 0.0f;
  ball->red = red; 
  ball->green = green; 
  ball->blue = blue; 

  return ball;

}

Platform* initPlatform(
  float mass,
  float x,
  float y,
  float w,
  float h,
  float red,
  float green,
  float blue
) {

  Platform* platform;

  if (!(platform = (Platform*) malloc(sizeof(Platform)))) {
    free(platform);
    return NULL;
  }

  if (!(platform->entity = (EntityProperties*) malloc(sizeof(EntityProperties)))) {
    free(platform->entity);
    free(platform);
    return NULL;
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

  return platform;

}
