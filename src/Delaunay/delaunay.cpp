#include <Delaunay/delaunay.hpp>
#include <ConvexHull/convex_hull.hpp>
#include <iostream>
#include <algorithm>

namespace aac {
 
DelaunayTriangulation::DelaunayTriangulation(const std::vector<Point>& points)
    : _points(points)
{
}

/**
 * Calculates the convex hull using Jarvis March algorithm
 */
void DelaunayTriangulation::calculateConvexHull() {
    _hull = aac::jarvis_march(_points);
}

/**
 * Creates triangles with all points in the convex hull
 */
void DelaunayTriangulation::triangulateConvexHull() {
    for (int i = 0; i < _hull.size() - 2; ++i) {
        _triangles.push_back(aac::Triangle(_hull[0], _hull[i + 1], _hull[i + 2]));
    }
}

/**
 * Creates triangles with all points that are not in the convex hull
 */
void DelaunayTriangulation::triangulateOtherPoints() {
    std::vector<Triangle> triangles_to_remove;
    std::vector<Triangle> triangles_to_add;

    for (const auto& point : _points) {
        if (std::find(_hull.cbegin(), _hull.cend(), point) != _hull.cend()) {
            continue; // Le point fait partie de l'enveloppe convexe
        }

        auto triangle_it = std::find_if(
            _triangles.cbegin(),
            _triangles.cend(),
            [&point](const Triangle& triangle) {
                return triangle.contains(point);
            }
        );
        if (triangle_it == _triangles.cend()) {
            std::cerr << "Point " << point << " n'est dans aucun triangle\n";
            continue;
        }

        auto triangle = *triangle_it;
        _triangles.push_back(Triangle(triangle.get_p1(), point, triangle.get_p3()));
        _triangles.push_back(Triangle(triangle.get_p2(), point, triangle.get_p3()));
        _triangles.push_back(Triangle(triangle.get_p1(), point, triangle.get_p2()));
        _triangles.erase(std::remove(_triangles.begin(), _triangles.end(), triangle), _triangles.end());
    }
}

std::vector<Triangle> DelaunayTriangulation::evaluate() {
    calculateConvexHull();
    triangulateConvexHull();
    triangulateOtherPoints();

    return _triangles;
}

} // namespace aac
