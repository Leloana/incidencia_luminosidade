#include <iostream>
#include "../include/Line.h"
#include "../include/Geometry.h"

using namespace std;

Line::Line(int id, int rf, double x, double y, double endX, double endY)
    : Obstacles(id, rf, x, y) 
{
    this->endPosition.x = endX;
    this->endPosition.y = endY;
}

void Line::printData(ostream& os) const{
    os << "L " << Id << " " <<
     reductionFactor << " " << position.x 
     << " " << position.y << " " << 
     endPosition.x << " " << endPosition.y 
     << endl;
}

int Line::countIntersections(Point p1, Point p2) const {
    return Geometry::intersectSegments(p1, p2, position, endPosition) ? 1 : 0;
}