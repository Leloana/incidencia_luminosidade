#include <iostream>
#include "../include/Line.h"

using namespace std;

void Line::printData() const{
    cout << "Line: " << Id << " " <<
     reductionFactor << " " << position.x 
     << " " << position.y << " " << 
     endPosition.x << " " << endPosition.y 
     << endl;
}