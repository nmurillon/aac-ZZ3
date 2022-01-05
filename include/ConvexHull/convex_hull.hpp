#ifndef CONVEX_HULL_HPP
#define CONVEX_HULL_HPP

#include <vector>
#include <Geometry/point.hpp>

namespace aac {

/**
 * Jarvis March Algorithm (Gift-wrapping) used to compute
 * the convex hull of a set of points
 * 
 * \param points A vector of points
 * \return A vector containing the convex hull of the set
 * 
 */
std::vector<Point> jarvis_march(const std::vector<Point>& points);

} // namespace aac

#endif // CONVEX_HULL_HPP
