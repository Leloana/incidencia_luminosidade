#include <iostream> 
#include "../include/Rectangle.h" 

using namespace std;

void Rectangle::printData() const{
    cout << "Rectangle: " << Id << " " 
    << reductionFactor << " " << position.x 
    << " " << position.y << " " << width << " " 
    << height << endl;
}