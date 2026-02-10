#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Obstacles.h"

class Rectangle : public Obstacles {
    public:
        int width;
        int height;
        void printData() const override;
};

#endif