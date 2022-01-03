#pragma once

#include <iterator>
#include <vector>
#include <stack>
#include <algorithm>
#include <set>
#include <geometry.hpp>

namespace aac {

class PolarAngleOrdering {
private:
    Point _point;

public:
    PolarAngleOrdering(const Point& point)
        : _point(point) {
    }

    double polar_angle(const Point& point) {
        auto delta = _point - point;
        return std::atan2(delta.get_y(), delta.get_x());
    }

    void set_point(const Point& point) {
        _point = point;
    }

    bool operator()(const Point& p1, const Point& p2) {
        return polar_angle(p1) < polar_angle(p2);
    }
};

std::vector<Point> graham_scan(const std::vector<Point>& points) {

    std::stack<Point> stack;
    auto p0 = *std::min(
        points.cbegin(),
        points.cend(),
        [](const Point& p1, const Point& p2) {
            if (p1.get_x() < p2.get_x()) return true;
            if (p2.get_x() < p1.get_x()) return false;
            if (p1.get_y() < p2.get_y()) return true;
            if (p2.get_y() < p1.get_y()) return false;
        }
    );
    PolarAngleOrdering ordering(p0);
    std::set<Point, PolarAngleOrdering> ordered_points(ordering);
    std::for_each(
        points.cbegin(),
        points.cend(),
        std::inserter(ordered_points, ordered_points.begin())
    );

    for(const auto& point : ordered_points) {
        while (stack.size() > 1 && )
    }
}