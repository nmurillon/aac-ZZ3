#ifndef DELAUNAY_HPP
#define DELAUNAY_HPP

#include <Geometry/triangle.hpp>
#include <vector>

namespace aac {

class DelaunayTriangulation {
private:
    std::vector<Point> _points;
    std::vector<Point> _hull;
    std::vector<Triangle> _triangles;

    void calculateConvexHull();
    void triangulateConvexHull();
    void triangulateOtherPoints();

public:
    DelaunayTriangulation(const std::vector<Point>& points);

    std::vector<Triangle> evaluate();
};

} // name

#endif // DELAUNAY_HPP
