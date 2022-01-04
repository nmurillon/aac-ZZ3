#include <ConvexHull/convex_hull.hpp>
#include <iostream>

namespace aac {

std::vector<Point> jarvis_march(const std::vector<Point>& points) {
    if (points.size() < 3) {
        return {};
    }

    auto starting_point = *std::min_element(points.begin(), points.end(), [](const Point& p1, const Point& p2) {
        return p1.get_x() < p2.get_x();
    });
    std::vector<Point> hull;
    Point end_point;

    do {
        hull.push_back(starting_point);
        end_point = points[0];

        for(auto i = 1u; i < points.size(); ++i) {
            if (starting_point == end_point 
            || orientation(starting_point, end_point, points[i]) == -1) {
                end_point = points[i];
            }
        }

        starting_point = end_point;
    } while (end_point != hull[0]);
    
    return hull;
}

}