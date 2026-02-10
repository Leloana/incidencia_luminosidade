#include <iostream> 
#include "../include/Rectangle.h" 

using namespace std;


Rectangle::Rectangle(int id, float rf, int x, int y, int w, int h)
    : Obstacles(id, rf, x, y) 
{
    this->width = w;
    this->height = h;
}


void Rectangle::printData() const{
    cout << "Rectangle: " << Id << " " 
    << reductionFactor << " " << position.x 
    << " " << position.y << " " << width << " " 
    << height << endl;
}