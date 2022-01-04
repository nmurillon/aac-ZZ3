#ifndef ORIENTATION_HPP
#define ORIENTATION_HPP

#include <Geometry/point.hpp>

namespace aac {

bool counter_clockwise(const Point& p1, const Point& p2, const Point& p3);
int orientation(const Point& p1, const Point& p2, const Point& p3);

} // namespace aac

#endif // ORIENTATION_HPP
