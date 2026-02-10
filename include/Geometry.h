#ifndef GEOMETRY_H
#define GEOMETRY_H
#include "Point.h"
#include <cmath>

namespace Geometry {

    bool isPointOnSegment(Point p, Point s1, Point s2);
    bool intersectSegments(Point a, Point b, Point c, Point d);

}
#endif