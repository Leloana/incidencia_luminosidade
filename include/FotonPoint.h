#define FOTONPOINT_H
#ifdef FOTONPOINT_H
#include "Point.h"

class FotonPoint {
    public:
        int Id;
        double intensity;
        Point position;

        FotonPoint(int id, double intensity, double x, double y);
        void printData(std::ostream& os) const;
};

#endif