#define LINE_H
#ifdef LINE_H
#include "Obstacles.h"

class Line : public Obstacles {
    public:
        Point endPosition;

        Line(int id, float rf, int x, int y, int endX, int endY);
        void printData() const override;
};

#endif