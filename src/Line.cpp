#include <iostream>
#include "../include/Line.h"

using namespace std;

Line::Line(int id, float rf, int x, int y, int endX, int endY)
    : Obstacles(id, rf, x, y) 
{
    this->endPosition.x = endX;
    this->endPosition.y = endY;
}

void Line::printData() const{
    cout << "Line: " << Id << " " <<
     reductionFactor << " " << position.x 
     << " " << position.y << " " << 
     endPosition.x << " " << endPosition.y 
     << endl;
}