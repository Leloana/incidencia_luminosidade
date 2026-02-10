#define TARGETPOINT_H
#ifdef TARGETPOINT_H
#include "Point.h"

class TargetPoint {
    public:
        int Id;
        Point position;
        double totalLuminosity; 

        TargetPoint(int id, double x, double y);
        void printData(std::ostream& os) const;
};

#endif