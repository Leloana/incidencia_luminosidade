#define LINE_H
#ifdef LINE_H
#include "Obstacles.h"

class Line : public Obstacles {
    public:
        Point endPosition;

        Line(int id, int rf, double x, double y, double endX, double endY);
        int countIntersections(Point p1, Point p2) const override;
        void printData(std::ostream& os) const override;
};

#endif