#ifndef OBSTACLES_H
#define OBSTACLES_H

#include "Point.h" 

class Obstacles {
    public:
        int Id;
        float reductionFactor;
        Point position;

        virtual void printData() const = 0;

        virtual ~Obstacles() {}
};

#endif