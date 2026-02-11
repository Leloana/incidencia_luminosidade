#ifndef CIRCLE_H
#define CIRCLE_H

#include "Obstacles.h"

/*
 * @file Circle.h
 * @brief Representa um círculo como um obstáculo geométrico.
 * Um círculo é definido por um centro (x, y) e um raio.
 * Esta classe herda de Obstacles e implementa métodos específicos para
 * calcular interseções com segmentos de reta.
*/

class Circle : public Obstacles {
    public:
        int radius;
        /**
         * @brief Construtor do obstáculo circular.
         * @param id Identificador do obstáculo.
         * @param rf Fator de redução da luz ao cruzar o obstáculo.
         * @param x Coordenada X do centro do círculo.
         * @param y Coordenada Y do centro do círculo.
         * @param r Raio do círculo.
         */
        Circle(int id, int rf, double x, double y, int r);
        /**
         * @brief Calcula a quantidade de interseções entre um raio de luz e o círculo.
         * @param p1 Ponto de origem do raio de luz.
         * @param p2 Ponto de destino (alvo) do raio de luz.
         * @return O número de colisões (0, 1 (tangente), ou 2 (travessia)).
         */
        int countIntersections(Point p1, Point p2) const override;
        /**
         * @brief Imprime os dados do círculo em um fluxo de saída.
         * @param os Fluxo de saída.
         */
        void printData(std::ostream& os) const override;
};

#endif