#define FOTONPOINT_H
#ifdef FOTONPOINT_H
#include "Point.h"

class FotonPoint {
    public:
        int Id;
        float intensity;
        Point position;
        void printData() const;
};

#endif