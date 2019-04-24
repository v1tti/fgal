#ifndef LINE_H
#define LINE_H

#include "point2d.h"

namespace fgal {
namespace types {
    struct Line
    {
        Point2D p1;
        Point2D p2;
        Line(Point2D _p1, Point2D _p2) : p1(_p1), p2(_p2) {}
    };
}
}

#endif