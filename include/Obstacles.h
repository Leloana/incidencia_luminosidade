#ifndef OBSTACLES_H
#define OBSTACLES_H
#include <iostream>
#include "Point.h" 

/*
 * @file Obstacles.h
 * @brief Representa um obstáculo geométrico genérico.
 * Esta classe é a base para todos os tipos de obstáculos geométricos.
 * Um obstáculo é definido por um identificador, um fator de redução da luz e uma posição (x, y).
*/

class Obstacles {
    public:
        int Id;
        int reductionFactor;
        Point position;

        /**
         * @brief Construtor do obstáculo genérico.
         * @param id Identificador do obstáculo.
         * @param rf Fator de redução da luz ao cruzar o obstáculo.
         * @param x Coordenada X do ponto inicial do retângulo.
         * @param y Coordenada Y do ponto inicial do retângulo.
         */
        Obstacles(int id, int rf, double x, double y);

        /**
         * @brief Calcula o número de interseções entre um raio de luz e o obstáculo.
         * * Este é um método virtual. A implementação padrão retorna 0, mas deve 
         * ser sobrescrita (overridden) pelas classes filhas (Rectangle, Circle, Line) 
         * com suas respectivas lógicas geométricas de colisão.
         * * @param p1 Ponto de origem do raio de luz.
         * @param p2 Ponto alvo (destino) do raio de luz.
         * @return O número de vezes que a luz cruza a fronteira do obstáculo.
         */
        virtual int countIntersections(Point p1, Point p2) const { return 0; }

        /**
         * @brief Imprime os dados estruturais do obstáculo.
         * * Este é um método virtual puro (= 0), o que torna Obstacles uma classe abstrata.
         * Toda classe filha é OBRIGADA a implementar este método para formatar
         * a saída de seus dados (ex: escrevendo no console ou em um arquivo .txt).
         * * @param os Fluxo de saída de dados (ex: std::cout ou std::ofstream).
         */
        virtual void printData(std::ostream& os) const = 0;

        /**
         * @brief Destrutor virtual padrão.
         * * Essencial em classes base com polimorfismo. Garante que, ao deletar um 
         * ponteiro do tipo Obstacles*, o destrutor correto da classe filha 
         * (Rectangle, Circle, etc.) seja chamado, evitando vazamento de memória.
         */
        virtual ~Obstacles() {}
};

#endif