#ifndef OBSTACLE_H
#define OBSTACLE_H

#include <random>
#include <vector>
#include "SDL.h"


//Obstacle class to create and place obstacles on the snake game screen.

class Obstacle {
 public:
  Obstacle();
  ~Obstacle();
  void setLocation(int x, int y);
  int getx();
  int gety();
  bool obstacleCell(int x, int y);

 private:
    SDL_Point obstacle;
};

#endif
