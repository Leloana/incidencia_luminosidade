#include <iostream> 
#include "../include/Obstacles.h" 

using namespace std;

/**
 * @file Obstacles.cpp
 * @brief Implementação dos métodos do módulo de obstáculos.
 * * Veja detalhes da interface e documentação dos parâmetros no arquivo Obstacles.h.
 */

Obstacles::Obstacles (int id, int rf, double x, double y) 
    : Id(id)
{
    this->reductionFactor = rf;
    this->position.x = x;
    this->position.y = y;
}