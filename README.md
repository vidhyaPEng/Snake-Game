# CPPND: Capstone Snake Game Example

Snake Game Levels 1 and 2:
<img src=SnakeGameLevel1&2.png>

Snake Game Level3:
<img src=SnakeGameLevel3.png>

The code for this repo was inspired by [this](https://codereview.stackexchange.com/questions/212296/snake-game-in-c-with-sdl) excellent StackOverflow post and set of responses.
This project was created as a Capstone Project for the Undacity C++ Nanodegree.  This is a modification of the Snake Game in which the player can choose from three different levels of difficulty:
	1. Level 1 is the easiest where the snake travels at a constant speed and there are no obstacles.
	2. Level 2 is where the snake increases its speed after consuming each food piece. 
	3. Level 3 is where the snake increases its speed after consuming food and also has to avoid obstacles placed on the game screen at random locations.
As the Snake consumes food, it grows longer, making it more and more difficult to navigate around the game screen.  If during the game the snake hits its own body or any of the obstacles, the game ends.

## Rubric Requirements

Loops, Functions, I/O:
	1. The project demonstrates an understanding of C++ functions and control structures.
		a. if-statements used to change the execution of the game based on the level selected: game.cpp (lines 19 - 26, 38 - 40 and 80 - 87).  
		b. The project is clearly organized into functions: all of obstacle.h, obstacle.cpp, game.h and game.cpp(lines 19 - 26, 91 -110 and 112 -1 20). 
	2. The project accepts user input and processes the input.
		a. The project asks for user to select the level before starting the game: main.cpp (lines 9 -13 and line 25).

Object Oriented Programming:
	1. The project uses Object Oriented Programming techniques.
		a. Addtion of obstacle class to add obstacles to the game: obstacle.h and obstacle.cpp.  Class methods are defined to set obstacle location, get location and check if a cell is occupied by the obstacle.
	2. Classes use appropriate access specifiers for class members.
		a. New public and private methods and variables were added in game.h (lines 23, 28 - 31, 33, 34, 44, and 45).
	3. Classes abstract implementation details from their interfaces.
		a. All class member functions document their effects through comments and function names: game.h(lines 45 adn 46), obstacle.h(lines 15 - 18).
	4. Classes encapsulate behaviour.
		a.  Appropriate data and functions are grouped into classes: addition of obstacle.h and obstacle.cpp to capture obstacles on the game screen. 
		b. State is accessed via member functions: game.cpp(lines 21 - 28), obstacle.cpp (lines 8 - 20)

Memory Management:
	1. The project makes use of references in function declarations.
		a. The vector of obstacles is passed to the renderer class as a reference: renderer.cpp(line 41).
	2. The project uses destructors appropriately.
		a. Obstacle class and game class have desctructors to ensure that memory is cleared properly: obstacle.h(line 14), obstacle.cpp(line 6),  game.h(line 18), and game.cpp(line 18)
	3. The project uses move semantics to move data, instaead of copying it, where possible.
		a. Each obstacle is created as a unique pointer and moved to the vector of unique pointers: game.cpp(line 99).
	4. The project uses smart pointers instead of raw pointers
		a. The obstacles are created as a vector of unique pointers: game.h(line 30) and game.cpp(lines 98 - 100).



## Basic Build and Game Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`.
5.Select level 1, 2 or 3 to start playing.

## Dependencies for Running Locally

* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  >Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source. 
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)


## CC Attribution-ShareAlike 4.0 International


Shield: [![CC BY-SA 4.0][cc-by-sa-shield]][cc-by-sa]

This work is licensed under a
[Creative Commons Attribution-ShareAlike 4.0 International License][cc-by-sa].

[![CC BY-SA 4.0][cc-by-sa-image]][cc-by-sa]

[cc-by-sa]: http://creativecommons.org/licenses/by-sa/4.0/
[cc-by-sa-image]: https://licensebuttons.net/l/by-sa/4.0/88x31.png
[cc-by-sa-shield]: https://img.shields.io/badge/License-CC%20BY--SA%204.0-lightgrey.svg
