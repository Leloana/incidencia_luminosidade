/**
 * @file Geometry.cpp
 * @brief Funções utilitárias para cálculos geométricos bidimensionais.
 * * Contém algoritmos para verificação de colinearidade e interseção de segmentos
 * utilizando o teste de orientação por produto vetorial.
 */

#include "Geometry.h"
#include <cmath>

/**
 * Verifica se o ponto 'p' reside dentro do segmento definido por 's1' e 's2'.
 * Utiliza a soma das distâncias com uma tolerância (epsilon) para evitar erros de precisão de ponto flutuante.
 */
bool Geometry::isPointOnSegment(Point p, Point s1, Point s2) {
    double epsilon = 1e-7;
    double distTotal = std::sqrt(std::pow(s1.x - s2.x, 2) + std::pow(s1.y - s2.y, 2));
    double distP = std::sqrt(std::pow(s1.x - p.x, 2) + std::pow(s1.y - p.y, 2)) +
                   std::sqrt(std::pow(s2.x - p.x, 2) + std::pow(s2.y - p.y, 2));
    
    return std::abs(distTotal - distP) < epsilon;
}

/**
 * Determina se dois segmentos de reta (ab e cd) se cruzam.
 */
bool Geometry::intersectSegments(Point a, Point b, Point c, Point d) {
    /**
     * Função Lambda CCW (Counter-Clockwise):
     * Calcula a orientação do trio de pontos (p1, p2, p3).
     * 0 -> Colineares | 1 -> Horário | 2 -> Anti-horário
     */
    auto ccw = [](Point p1, Point p2, Point p3) {
        double val = (p2.y - p1.y) * (p3.x - p2.x) - (p2.x - p1.x) * (p3.y - p2.y);
        if (std::abs(val) < 1e-9) return 0;
        return (val > 0) ? 1 : 2;
    };

    // Avalia a orientação de cada ponto de um segmento em relação ao outro segmento
    int r1 = ccw(a, b, c), r2 = ccw(a, b, d);
    int r3 = ccw(c, d, a), r4 = ccw(c, d, b);

    // Caso Geral: As orientações são diferentes, indicando que os segmentos se cruzam
    if (r1 != r2 && r3 != r4) return true;

    // Casos Especiais: Pontos colineares que residem exatamente sobre o segmento oposto
    if (r1 == 0 && isPointOnSegment(c, a, b)) return true;
    if (r2 == 0 && isPointOnSegment(d, a, b)) return true;
    if (r3 == 0 && isPointOnSegment(a, c, d)) return true;
    if (r4 == 0 && isPointOnSegment(b, c, d)) return true;

    return false; // Não há interseção
}