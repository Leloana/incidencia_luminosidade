#ifndef LINE_H
#define LINE_H
#include "Obstacles.h"

/*
 * @file Line.h
 * @brief Representa uma linha como um obstáculo geométrico.
 * Uma linha é definida por dois pontos (x1, y1) e (x2, y2).
 * Esta classe herda de Obstacles e implementa métodos específicos para
 * calcular interseções com segmentos de reta.
*/

class Line : public Obstacles {
    public:
        Point endPosition;
        /**
         * @brief Construtor do obstáculo Linha.
         * @param id Identificador do obstáculo.
         * @param rf Fator de redução da luz ao cruzar o obstáculo.
         * @param x Coordenada X do ponto inicial da linha.
         * @param y Coordenada Y do ponto inicial da linha.
         * @param endX Coordenada X do ponto final da linha.
         * @param endY Coordenada Y do ponto final da linha.
         */
        Line(int id, int rf, double x, double y, double endX, double endY);
        /**
         * @brief Calcula a quantidade de interseções entre um raio de luz e a linha.
         * @param p1 Ponto de origem do raio de luz.
         * @param p2 Ponto de destino (alvo) do raio de luz.
         * @return O número de colisões (0, 1).
         */
        int countIntersections(Point p1, Point p2) const override;
        /**
         * @brief Imprime os dados da linha em um fluxo de saída.
         * @param os Fluxo de saída.
         */
        void printData(std::ostream& os) const override;
};

#endif