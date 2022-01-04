#ifndef CONVEX_HULL_HPP
#define CONVEX_HULL_HPP

#include <iterator>
#include <vector>
#include <stack>
#include <algorithm>
#include <set>
#include <Geometry/point.hpp>
#include <Geometry/orientation.hpp>

namespace aac {

std::vector<Point> jarvis_march(const std::vector<Point>& points);

} // namespace aac

#endif // CONVEX_HULL_HPP
