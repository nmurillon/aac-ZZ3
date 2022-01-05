#ifndef ORIENTATION_HPP
#define ORIENTATION_HPP

#include <Geometry/point.hpp>

namespace aac {

/**
 * Returns true if p1, p2, p3 are oriented counter clockwise
 */
bool counter_clockwise(const Point& p1, const Point& p2, const Point& p3);

/**
 * Checks the orientation of a triplet of points
 */
int orientation(const Point& p1, const Point& p2, const Point& p3);

} // namespace aac

#endif // ORIENTATION_HPP
