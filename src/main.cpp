#include <iostream>
#include "controller.h"
#include "game.h"
#include "renderer.h"

int main() {
  //user defined level
  int level;
  std::cout << "--------------------------------------" << std::endl;
  std::cout << "Please enter difficulty level" << std::endl;
  std::cout << "Easy: 1, Medium: 2, Hard: 3 " << std::endl;
  std::cout << "--------------------------------------" << std::endl;
  std::cin >> level;

  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  constexpr std::size_t kGridWidth{32};
  constexpr std::size_t kGridHeight{32};

  
  Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
  Controller controller;
  Game game(kGridWidth, kGridHeight, level);
  game.Run(controller, renderer, kMsPerFrame);
  
  std::cout << "Game has terminated successfully!\n";
  std::cout << "Score: " << game.GetScore() << "\n";
  std::cout << "Size: " << game.GetSize() << "\n";
  return 0;
}