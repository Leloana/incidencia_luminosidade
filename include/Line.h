#define LINE_H
#ifdef LINE_H
#include "Obstacles.h"

class Line : public Obstacles {
    public:
        Point endPosition;
        void printData() const override;
};

#endif