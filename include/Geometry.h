#ifndef GEOMETRY_H
#define GEOMETRY_H
#include "Point.h"
#include <cmath>

/*
 * @file Geometry.h
 * @brief Responsável pelas operações matemáticas e cálculos de interseção.
 * Este namespace contém métodos para resolver colisões entre pontos e
 * segmentos de reta
*/

namespace Geometry {

    /**
     * @brief Verifica se um ponto reside fisicamente sobre um segmento de reta.
     * * @param p O ponto a ser verificado.
     * @param s1 O ponto inicial do segmento de reta.
     * @param s2 O ponto final do segmento de reta.
     * @return true se o ponto 'p' estiver entre 's1' e 's2', false caso contrário.
     */
    bool isPointOnSegment(Point p, Point s1, Point s2);
    /**
     * @brief Verifica se dois segmentos de reta se cruzam.
     * * Utiliza o cálculo de orientação para determinar 
     * se as retas formadas por (a,b) e (c,d) se interceptam no plano.
     * * @param a Ponto inicial do primeiro segmento.
     * @param b Ponto final do primeiro segmento.
     * @param c Ponto inicial do segundo segmento.
     * @param d Ponto final do segundo segmento.
     * @return true se houver colisão entre os segmentos, false caso contrário.
     */
    bool intersectSegments(Point a, Point b, Point c, Point d);

}
#endif