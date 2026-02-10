#include <iostream>
#include "../include/TargetPoint.h"
using namespace std;

TargetPoint::TargetPoint(int id, int x, int y)
    : Id(id)
{
    this->position.x = x;
    this->position.y = y;
}

void TargetPoint::printData() const{
    cout << "TargetPoint: " << Id << " " << position.x << " " << position.y << endl;
}