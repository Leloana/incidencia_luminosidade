#include <iostream> 
#include "../include/Rectangle.h" 
#include "../include/Geometry.h"

using namespace std;

/**
 * @file Rectangle.cpp
 * @brief Implementação dos métodos do obstáculo retangular.
 * * Veja detalhes da interface e documentação dos parâmetros no arquivo Rectangle.h.
 */

Rectangle::Rectangle(int id, int rf, double x, double y, int w, int h)
    : Obstacles(id, rf, x, y) 
{
    this->width = w;
    this->height = h;
}


void Rectangle::printData(std::ostream& os) const{
    os << "R " << Id << " " 
    << reductionFactor << " " << position.x 
    << " " << position.y << " " << width << " " 
    << height << endl;
}

// Calcula interseções com as quatro arestas do retângulo
int Rectangle::countIntersections(Point p1, Point p2) const {
    // Define os quatro vértices do retângulo com base no ponto inicial (position) e suas dimensões (width, height)
    Point pA = position;
    Point pB = {position.x + width, position.y};
    Point pC = {position.x + width, position.y + height};
    Point pD = {position.x, position.y + height};
    
    int hits = 0;
    
    // 1. Testa as arestas normalmente como segmentos de reta usando o módulo Geometry
    if (Geometry::intersectSegments(p1, p2, pA, pB)) hits++;
    if (Geometry::intersectSegments(p1, p2, pB, pC)) hits++;
    if (Geometry::intersectSegments(p1, p2, pC, pD)) hits++;
    if (Geometry::intersectSegments(p1, p2, pD, pA)) hits++;
    
    // 2. Desconta as repetições se o raio passou exatamente em cima de um vértice
    if (Geometry::isPointOnSegment(pA, p1, p2)) hits--;
    if (Geometry::isPointOnSegment(pB, p1, p2)) hits--;
    if (Geometry::isPointOnSegment(pC, p1, p2)) hits--;
    if (Geometry::isPointOnSegment(pD, p1, p2)) hits--;
    
    return hits;
}