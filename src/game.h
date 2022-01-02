#ifndef GAME_H
#define GAME_H

#include <random>
#include <memory>
#include <set>
#include "SDL.h"
#include "controller.h"
#include "obstacle.h"
#include "renderer.h"
#include "snake.h"



class Game {
 public:
  Game(std::size_t grid_width, std::size_t grid_height, int level);
  ~Game();
 
  void Run(Controller const &controller, Renderer &renderer,
           std::size_t target_frame_duration);
  int GetScore() const;
  int GetSize() const;
  void SetLevel(int level);

 private:
  Snake snake;
  SDL_Point food;
  int _level;
  std::vector<std::unique_ptr<Obstacle>> Obstacles;
  bool ObstCoord = false;
  int _grid_width;
  int _grid_height;

  //Obstacle Location set
  std::set<int> _ObstX;
  std::set<int> _ObstY;
  

  std::random_device dev;
  std::mt19937 engine;
  std::uniform_int_distribution<int> random_w;
  std::uniform_int_distribution<int> random_h;

  int score{0};
  void PlaceFood();
  void initializeObstacles(int count);
  void detectCollision();
  void Update();
};

#endif