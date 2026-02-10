#define TARGETPOINT_H
#ifdef TARGETPOINT_H
#include "Point.h"

class TargetPoint {
    public:
        int Id;
        Point position;

        TargetPoint(int id, int x, int y);
        void printData() const;
};

#endif