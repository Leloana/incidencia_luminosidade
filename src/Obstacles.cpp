#include <iostream> 
#include "../include/Obstacles.h" 

using namespace std;

Obstacles::Obstacles (int id, float rf, int x, int y) 
    : Id(id)
{
    this->reductionFactor = rf;
    this->position.x = x;
    this->position.y = y;
}