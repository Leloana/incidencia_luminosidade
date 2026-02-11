#ifndef TARGETPOINT_H
#define TARGETPOINT_H
#include "Point.h"

/*
 * @file TargetPoint.h
 * @brief Representa um ponto-alvo como um alvo de incidência luminosa.
 * Um ponto-alvo é definido por um identificador, uma posição (x, y) e uma luminosidade total.
 * Esta classe implementa métodos específicos para representar e manipular pontos-alvo em um ambiente de incidência luminosa.
*/

class TargetPoint {
    public:
        int Id;
        Point position;
        double totalLuminosity; 

        /**
         * @brief Construtor do Ponto-Alvo.
         * @param id Identificador do ponto-alvo.
         * @param x Coordenada X do ponto-alvo.
         * @param y Coordenada Y do ponto-alvo.
         */
        TargetPoint(int id, double x, double y);
        /**
         * @brief Imprime os dados do ponto-alvo em um fluxo de saída.
         * @param os Fluxo de saída.
         */
        void printData(std::ostream& os) const;
};

#endif