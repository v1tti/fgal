#ifndef VECTOR2D_H
#define VECTOR2D_H

namespace fgal {
namespace types {
    struct Vector2D
    {
        int x;
        int y;
        Vector2D(int _x, int _y) : x(_x), y(_y) {}
    };    
}
}

#endif