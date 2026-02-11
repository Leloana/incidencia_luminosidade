#ifndef FOTONPOINT_H
#define FOTONPOINT_H
#include "Point.h"

/*
 * @file FotonPoint.h
 * @brief Representa um fóton como um ponto de luz.
 * Um fóton é definido por um identificador, uma intensidade e uma posição (x, y).
 * Esta classe implementa métodos específicos para
 * representar e manipular fótons em um ambiente de incidência luminosa.
*/

class FotonPoint {
    public:
        int Id;
        double intensity;
        Point position;
        /** 
         * @brief Construtor do fóton.
         * @param id Identificador do fóton.
         * @param intensity Intensidade do fóton.
         * @param x Coordenada X da posição do fóton.
         * @param y Coordenada Y da posição do fóton.
         */
        FotonPoint(int id, double intensity, double x, double y);
        /**
         * @brief Imprime os dados do fóton em um fluxo de saída.
         * @param os Fluxo de saída.
         */
        void printData(std::ostream& os) const;
};

#endif