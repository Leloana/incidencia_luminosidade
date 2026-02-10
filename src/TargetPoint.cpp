#include <iostream>
#include "../include/TargetPoint.h"
using namespace std;

void TargetPoint::printData() const{
    cout << "TargetPoint: " << Id << " " << position.x << " " << position.y << endl;
}