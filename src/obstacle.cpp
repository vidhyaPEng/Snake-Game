#include "obstacle.h"
#include <iostream>

Obstacle::Obstacle(){};

Obstacle::~Obstacle() {};

void Obstacle::setLocation(int x, int y){
    obstacle.x = x;
    obstacle.y = y;
};


int Obstacle::getx(){
    return {obstacle.x};
}

int Obstacle::gety(){
    return {obstacle.y};
}

bool Obstacle::obstacleCell(int x, int y){
    bool collision = false;
    if(x == obstacle.x && y == obstacle.y){
        collision = true;
    }
    return collision;
}