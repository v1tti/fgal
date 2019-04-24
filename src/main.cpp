#include <iostream>
#include "types/point2d.h"
#include "operations/operations.h"

int main() {
    fgal::types::Point2D p1(1, 1);
    fgal::types::Point2D p2(2, 1);

    std::cout << fgal::operations::points_distance(p1, p2) << std::endl;
}