#include <iostream> 
#include "../include/Rectangle.h" 
#include "../include/Geometry.h"

using namespace std;


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
    // Definição dos vértices com base na origem (canto inferior esquerdo), largura e altura
    Point pA = position;
    Point pB = {position.x + width, position.y};
    Point pC = {position.x + width, position.y + height};
    Point pD = {position.x, position.y + height};
    
    int hits = 0;
    // Testa a interseção do segmento p1-p2 com cada uma das quatro faces do retângulo
    if (Geometry::intersectSegments(p1, p2, pA, pB)) hits++;
    if (Geometry::intersectSegments(p1, p2, pB, pC)) hits++;
    if (Geometry::intersectSegments(p1, p2, pC, pD)) hits++;
    if (Geometry::intersectSegments(p1, p2, pD, pA)) hits++;
    
    return hits;
}