#include <iostream> 
#include "../include/Circle.h" 
#include "../include/Geometry.h"

using namespace std;

Circle::Circle(int id, int rf, double x, double y, int r)
    : Obstacles(id, rf, x, y) 
{
    this->radius = r;
}

void Circle::printData(std::ostream& os) const{
    os << "C " << Id << " " 
    << reductionFactor << " " << 
    position.x << " " << position.y << " " 
    << radius << endl;
}

// Utiliza a equação quadrática para encontrar interseções entre o segmento e a circunferência
int Circle::countIntersections(Point p1, Point p2) const {
    // Vetores diretores e diferença em relação ao centro do círculo
    double dx = p2.x - p1.x, dy = p2.y - p1.y;
    double fx = p1.x - position.x, fy = p1.y - position.y;

    // Coeficientes da equação at² + bt + c = 0 (interseção linha-esfera)
    double a = dx * dx + dy * dy;
    double b = 2 * (fx * dx + fy * dy);
    double c = (fx * fx + fy * fy) - (double)radius * radius;

    // O discriminante determina se há colisão (raízes reais)
    double disc = b * b - 4 * a * c;
    if (disc < 0) return 0; // Nenhuma interseção real

    disc = std::sqrt(disc);
    
    // t representa a posição relativa no segmento (0 <= t <= 1)
    double t1 = (-b - disc) / (2 * a), t2 = (-b + disc) / (2 * a);
    if (abs(t1 - t2) < 1e-5) { 
    // Se t1 e t2 são iguais, é uma tangente, conta apenas 1 hit se estiver no segmento
        if (t1 >= 0 && t1 <= 1) return 1;
        return 0;
    }
    int hits = 0;
    // Verifica se os pontos de interseção da reta infinita estão dentro do segmento p1-p2
    if (t1 >= 0 && t1 <= 1) hits++;
    if (t2 >= 0 && t2 <= 1) hits++;
    
    return hits;
}