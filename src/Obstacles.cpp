#include <iostream> 
#include "../include/Obstacles.h" 

using namespace std;

Obstacles::Obstacles (int id, int rf, double x, double y) 
    : Id(id)
{
    this->reductionFactor = rf;
    this->position.x = x;
    this->position.y = y;
}