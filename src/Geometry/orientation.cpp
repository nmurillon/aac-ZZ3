#include <Geometry/orientation.hpp>

namespace aac {

bool counter_clockwise(const Point& p1, const Point& p2, const Point& p3) {
    return orientation(p1, p2, p3) == -1;
}

int orientation(const Point& p1, const Point& p2, const Point& p3) {
    double val = ((p2.get_x() - p1.get_x()) * (p3.get_y() - p1.get_y())) 
               - ((p3.get_x() - p1.get_x()) * (p2.get_y() - p1.get_y()));
    if (val > 0) {
        return -1;
    } else if (val < 0) {
        return 1;
    } else {
        return 0;
    }
}

} // namespace aac
