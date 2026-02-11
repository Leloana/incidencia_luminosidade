#include <iostream>
#include "../include/FotonPoint.h"
using namespace std;

/**
 * @file FotonPoint.cpp
 * @brief Implementação dos métodos do ponto fonte de luz.
 * * Veja detalhes da interface e documentação dos parâmetros no arquivo FotonPoint.h.
 */

FotonPoint::FotonPoint(int id, double intensity, double x, double y)
    : Id(id), intensity(intensity)
{
    this->position.x = x;
    this->position.y = y;
}

void FotonPoint::printData(std::ostream& os) const{
    os << "F " << Id << " " << intensity << " " << position.x << " " << position.y << endl;
}