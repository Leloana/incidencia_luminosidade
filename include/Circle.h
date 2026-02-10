#define CIRCLE_H
#ifdef CIRCLE_H

#include "Obstacles.h"

class Circle : public Obstacles {
    public:
        int radius;

        Circle(int id, int rf, double x, double y, int r);
        int countIntersections(Point p1, Point p2) const override;
        void printData(std::ostream& os) const override;
};

#endif