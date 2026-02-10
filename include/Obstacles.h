#ifndef OBSTACLES_H
#define OBSTACLES_H
#include <iostream>
#include "Point.h" 

class Obstacles {
    public:
        int Id;
        int reductionFactor;
        Point position;


        Obstacles(int id, int rf, double x, double y);

        virtual int countIntersections(Point p1, Point p2) const { return 0; }
        virtual void printData(std::ostream& os) const = 0;
        virtual ~Obstacles() {}
};

#endif