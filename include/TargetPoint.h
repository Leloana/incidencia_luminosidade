#define TARGETPOINT_H
#ifdef TARGETPOINT_H
#include "Point.h"

class TargetPoint {
    public:
        int Id;
        Point position;
        void printData() const;
};

#endif