#define FOTONPOINT_H
#ifdef FOTONPOINT_H
#include "Point.h"

class FotonPoint {
    public:
        int Id;
        float intensity;
        Point position;

        FotonPoint(int id, float intensity, int x, int y);
        void printData() const;
};

#endif