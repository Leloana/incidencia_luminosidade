#include <iostream>
#include "../include/FotonPoint.h"
using namespace std;

void FotonPoint::printData() const{
    cout << "FotonPoint: " << Id << " " << intensity << " " << position.x << " " << position.y << endl;
}