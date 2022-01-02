#include <iostream>
#include "game.h"
#include <vector>
#include <set>
#include "SDL.h"



Game::Game(std::size_t grid_width, std::size_t grid_height, int level)
    : snake(grid_width, grid_height),
      engine(dev()),
      random_w(0, static_cast<int>(grid_width - 1)),
      random_h(0, static_cast<int>(grid_height - 1)),
      _grid_width(grid_width),
      _grid_height(grid_height) {
  PlaceFood();
  SetLevel(level);
}

Game::~Game(){}

//set user defined level for the game
void Game::SetLevel(int level){
  if (level > 0 && level <= 3){
    _level = level;
  } else {
    std::cout<< "Please select 1,2 or 3.  Game Aborted." << std::endl;
    SDL_Quit();
  }  
}

void Game::Run(Controller const &controller, Renderer &renderer,
               std::size_t target_frame_duration) {
  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;
  bool running = true;


  if (_level > 2){
    //select number of obstacles to initialize in the game
    initializeObstacles(6);
  } else {
    Obstacles.clear(); //ensure that the set is clear if level 3 is not being run.
  }

  while (running) {
    frame_start = SDL_GetTicks();

    // Input, Update, Render - the main game loop.
    controller.HandleInput(running, snake);
    Update();
    renderer.Render(snake, food, Obstacles);

    frame_end = SDL_GetTicks();

    // Keep track of how long each loop through the input/update/render cycle
    // takes.
    frame_count++;
    frame_duration = frame_end - frame_start;

    // After every second, update the window title.
    if (frame_end - title_timestamp >= 1000) {
      renderer.UpdateWindowTitle(score, frame_count);
      frame_count = 0;
      title_timestamp = frame_end;
    }

    // If the time for this frame is too small (i.e. frame_duration is
    // smaller than the target ms_per_frame), delay the loop to
    // achieve the correct frame rate.
    if (frame_duration < target_frame_duration) {
      SDL_Delay(target_frame_duration - frame_duration);
    }
  }
}

void Game::PlaceFood() {
  int x, y;
  while (true) {
    x = random_w(engine);
    y = random_h(engine);
    // Check that the location is not occupied by a snake item or obstacles before placing
    // food.
    if (_ObstX.count(x) != 0 && _ObstY.count(y) != 0){
      ObstCoord = true;
    } 
    if (!snake.SnakeCell(x, y) && !ObstCoord) {
      food.x = x;
      food.y = y;
      return;
    }
  }
}

void Game::initializeObstacles(int count){
  int x, y;
  std::set<int>::iterator itX;
  std::set<int>::iterator itY;
  Obstacles.clear();//ensure set is empty.

      //insert values into set
      for (int i = 0; i < count; i++){
        Obstacles.emplace_back(std::make_unique<Obstacle>());
      }
      while(_ObstX.size() != Obstacles.size()){
      x = random_w(engine);
      //ensure that the x co-ordinates of the obstacles are visible on the game screen
      //ensure that the x and y co-ordinates of the obstacles are not at the starting postion of the snake(centre of game screen)
        if (x > 0 && x < _grid_width-1 && x != _grid_width/2) {
            _ObstX.insert(x);
        }
      }
      while(_ObstY.size() != Obstacles.size()){
        y = random_h(engine);
        //ensure that the y co-ordinates of the obstacles are visible on the game screen
        if (y > 0 && y < _grid_height-1 && y != _grid_height/2){
            _ObstY.insert(y);
        } 
      }
      //set obstacle location
      itX = _ObstX.begin();
      itY = _ObstY.begin();
      for(int i = 0; i < count; i++){
        Obstacles[i].get()->setLocation(*itX,*itY);
        itX++;
        itY++;
      }   
}

void Game::detectCollision(){
  int snakeHeadX = static_cast<int>(snake.head_x);
  int snakeHeadY = static_cast<int>(snake.head_y);
  for(int i=0; i < Obstacles.size(); i++){
    if(Obstacles[i].get()->obstacleCell(snakeHeadX, snakeHeadY)){
      snake.alive = false;
    }
  }
}

void Game::Update() {
  if (!snake.alive) return;

  snake.Update();

  if (_level > 2){
    detectCollision();
  }

  int new_x = static_cast<int>(snake.head_x);
  int new_y = static_cast<int>(snake.head_y);

  // Check if there's food over here
  if (food.x == new_x && food.y == new_y) {
    score++;
    PlaceFood();
    // Grow snake 
    snake.GrowBody();
    //increase speed based on level
    if (_level > 1){
        snake.speed += 0.02;
    }
  }

}

int Game::GetScore() const { return score; }
int Game::GetSize() const { return snake.size; }