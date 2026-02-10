#define CIRCLE_H
#ifdef CIRCLE_H

#include "Obstacles.h"

class Circle : public Obstacles {
    public:
        int radius;
        void printData() const override;
};

#endif