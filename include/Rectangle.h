#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Obstacles.h"

class Rectangle : public Obstacles {
    public:
        int width;
        int height;

        Rectangle(int id, float rf, int x, int y, int w, int h);
        void printData() const override;
};

#endif