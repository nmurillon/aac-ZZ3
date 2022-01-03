#pragma once

#include <cmath>

namespace aac {


// TODO: module & argument, std::hash ?
class Point {
private:
    double _x;
    double _y;

public:
    Point()
        : Point(0, 0) {}
    Point(double x, double y)
        : _x(x), _y(y) {}

    inline double get_x() const;
    inline double get_y() const;
    inline double squared_distance(const Point& other) const;
    inline double distance(const Point& other) const;
    inline double dot(const Point& other) const;

    Point operator-() const {
        return Point(-get_x(), -get_y());
    }
};

Point operator+(const Point& p1, const Point& p2) {
    return Point(p1.get_x() + p2.get_x(), p1.get_y() + p2.get_y());
}

Point operator-(const Point& p1, const Point& p2) {
    return p1 + (-p2);
}

double Point::get_x() const {
    return _x;
}

double Point::get_y() const {
    return _y;
}

double Point::squared_distance(const Point& other) const {
    return (_x - other.get_x()) * (_x - other.get_x()) 
         + (_y - other.get_y()) * (_y - other.get_y());
}

double Point::distance(const Point& other) const {
    return sqrt(squared_distance(other));
}

double Point::dot(const Point& other) const {
    return _x * other.get_x() + _y * other.get_y();
}

bool counter_clockwise(const Point& p1, const Point& p2, const Point& p3) {
    // si 0, colinéaire !!
    // return (
    //     (p2.get_x() - p1.get_x()) * ()  
    // )
    return true;
}

} // namespace aac

