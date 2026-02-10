#include <iostream>
#include "../include/FotonPoint.h"
using namespace std;

FotonPoint::FotonPoint(int id, float intensity, int x, int y)
    : Id(id), intensity(intensity)
{
    this->position.x = x;
    this->position.y = y;
}

void FotonPoint::printData() const{
    cout << "FotonPoint: " << Id << " " << intensity << " " << position.x << " " << position.y << endl;
}