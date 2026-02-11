#include "Geometry.h"
#include <cmath>
using namespace std;

/**
 * @file Geometry.cpp
 * @brief Implementação dos métodos do módulo de geometria.
 * * Veja detalhes da interface e documentação dos parâmetros no arquivo Geometry.h.
 */

bool Geometry::isPointOnSegment(Point p, Point s1, Point s2) {
    double epsilon = 1e-7; // Pontos flutuantes podem variar em suas ultimas casas decimais, então usamos um epsilon para comparação
    double distTotal = sqrt(pow(s1.x - s2.x, 2) + pow(s1.y - s2.y, 2)); //Distancia dos pontos do segmento alvo
    double distP = sqrt(pow(s1.x - p.x, 2) + pow(s1.y - p.y, 2)) + sqrt(pow(s2.x - p.x, 2) + pow(s2.y - p.y, 2));//distnacia do ponto P aos pontos do segmento alvo
    // Se a distancia P for maior, esta fora da linha, se for menor ou igual esta dentro da linha
    return abs(distTotal - distP) < epsilon; 
}

bool Geometry::intersectSegments(Point a, Point b, Point c, Point d) {
    // Algoritmo para determinar orientacao de um ponto em relacao a um segmento
    auto ccw = [](Point p1, Point p2, Point p3) {
        double val = (p2.y - p1.y) * (p3.x - p2.x) - (p2.x - p1.x) * (p3.y - p2.y);
        if (abs(val) < 1e-9) return 0; // Primeiro checa se nao houve curva (esta na linha)
        return (val > 0) ? 1 : 2; // 1 = anti-horario, 2 = horario
    };

    // Avalia a orientação de cada ponto de um segmento em relação ao outro segmento
    int r1 = ccw(a, b, c);
    int r2 = ccw(a, b, d);
    int r3 = ccw(c, d, a);
    int r4 = ccw(c, d, b);

    // Caso Geral: As orientações são diferentes, indicando que os segmentos se cruzam
    if (r1 != r2 && r3 != r4) return true;

    // Casos Especiais: Pontos colineares que residem exatamente sobre o segmento oposto
    if (r1 == 0 && isPointOnSegment(c, a, b)) return true;
    if (r2 == 0 && isPointOnSegment(d, a, b)) return true;
    if (r3 == 0 && isPointOnSegment(a, c, d)) return true;
    if (r4 == 0 && isPointOnSegment(b, c, d)) return true;

    return false; // Não há interseção
}