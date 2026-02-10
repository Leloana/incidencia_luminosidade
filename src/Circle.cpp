#include <iostream> 
#include "../include/Circle.h" 

using namespace std;

void Circle::printData() const{
    cout << "Circle: " << Id << " " 
    << reductionFactor << " " << 
    position.x << " " << position.y << " " 
    << radius << endl;
}