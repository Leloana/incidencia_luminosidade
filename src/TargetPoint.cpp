#include <iostream>
#include "../include/TargetPoint.h"
using namespace std;

TargetPoint::TargetPoint(int id, double x, double y)
    : Id(id)
{
    this->position.x = x;
    this->position.y = y;
    this->totalLuminosity = 0.0;
}

void TargetPoint::printData(std::ostream& os) const{
    os << "P " << Id << " " << position.x << " " << position.y << endl;
}