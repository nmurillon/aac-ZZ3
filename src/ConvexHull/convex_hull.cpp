#include <algorithm>
#include <iostream>
#include <ConvexHull/convex_hull.hpp>
#include <Geometry/orientation.hpp>

namespace aac {

/**
* Calculate the convex hull of a set of points
* using jarvis march method
* @param points : the set of points
*/ 
std::vector<Point> jarvis_march(const std::vector<Point>& points) {
    if (points.size() < 3) {
        return {};
    }

    /* Starting with the Point of min abscissa */
    auto starting_point = *std::min_element(
        points.begin(),
        points.end(),
        [](const Point& p1, const Point& p2) {
            return p1.get_x() < p2.get_x();
        }
    );
    std::vector<Point> hull;
    Point end_point;

    do {
        hull.push_back(starting_point);
        end_point = points[0];

        /* Search for the point with the minimum polar angle with starting_point */
        for(auto i = 1u; i < points.size(); ++i) {
            if (starting_point == end_point 
            || counter_clockwise(starting_point, end_point, points[i])) {
                end_point = points[i];
            }
        }

        starting_point = end_point;
    } while (end_point != hull[0]);
    
    return hull;
}

}