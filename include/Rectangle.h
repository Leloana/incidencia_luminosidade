#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Obstacles.h"

class Rectangle : public Obstacles {
    public:
        int width;
        int height;

        Rectangle(int id, int rf, double x, double y, int w, int h);
        int countIntersections(Point p1, Point p2) const override;
        void printData(std::ostream& os) const override;
};

#endif