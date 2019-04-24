#ifndef POINT2D_H
#define POINT2D_H

namespace fgal {
namespace types {
    struct Point2D {
        int x;
        int y;
        Point2D(int _x, int _y) : x(_x), y(_y) {};
    };
}
}

#endif