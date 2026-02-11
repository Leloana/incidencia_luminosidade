#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Obstacles.h"

/*
 * @file Rectangle.h
 * @brief Representa um retângulo como um obstáculo geométrico.
 * Um retângulo é definido por um ponto inicial (x, y), uma largura e uma altura.
 * Esta classe herda de Obstacles e implementa métodos específicos para
 * calcular interseções com segmentos de reta.
*/

class Rectangle : public Obstacles {
    public:
        int width;
        int height;
        /**
         * @brief Construtor do obstáculo Retângulo.
         * @param id Identificador do obstáculo.
         * @param rf Fator de redução da luz ao cruzar o obstáculo.
         * @param x Coordenada X do ponto inicial do retângulo.
         * @param y Coordenada Y do ponto inicial do retângulo.
         * @param w Largura do retângulo.
         * @param h Altura do retângulo.
         */
        Rectangle(int id, int rf, double x, double y, int w, int h);
        /**
         * @brief Calcula a quantidade de interseções entre um raio de luz e o retângulo.
         * @param p1 Ponto de origem do raio de luz.
         * @param p2 Ponto de destino (alvo) do raio de luz.
         * @return O número de colisões (0 , 2).
         */
        int countIntersections(Point p1, Point p2) const override;
        /**
         * @brief Imprime os dados do retângulo em um fluxo de saída.
         * @param os Fluxo de saída.
         */
        void printData(std::ostream& os) const override;
};

#endif