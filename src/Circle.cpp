#include <iostream> 
#include "../include/Circle.h" 

using namespace std;

Circle::Circle(int id, float rf, int x, int y, int r)
    : Obstacles(id, rf, x, y) 
{
    this->radius = r;
}

void Circle::printData() const{
    cout << "Circle: " << Id << " " 
    << reductionFactor << " " << 
    position.x << " " << position.y << " " 
    << radius << endl;
}