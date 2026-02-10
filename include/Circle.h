#define CIRCLE_H
#ifdef CIRCLE_H

#include "Obstacles.h"

class Circle : public Obstacles {
    public:
        int radius;

        Circle(int id, float rf, int x, int y, int r);
        void printData() const override;
};

#endif