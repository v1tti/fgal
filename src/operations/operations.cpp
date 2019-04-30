#include <cmath>
#include "operations/operations.h"

namespace fgal {
namespace operations {
    float points_distance(types::Point2D p1, types::Point2D p2) {
        return sqrt(
            pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2)
        );
    }

    types::Vector2D vectors_sum(types::Vector2D v1, types::Vector2D v2) {
        return types::Vector2D(v1.x + v2.x, v1.y + v2.y);

    }
    float angle_between(types::Vector2D v1, types::Vector2D v2){
        float dp = (v1.x*v2.x)+(v1.y*v2.y);
        if (dp >= 1.0){
            dp = 1.0f;
        }
        else if (dp <= -1.0){
            dp = -1.0f;
        }
        float angpi = (float) acos(dp);
        return (v2) >0 ? -angpi : angpi;
    }
}
}