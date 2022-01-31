#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "point.hpp"
#include "orientation.hpp"

namespace aac {

class Triangle {
private:
    Point _p1;
    Point _p2;
    Point _p3;

public:
    Triangle(const Point& p1, const Point& p2, const Point& p3)
        : _p1(p1), _p2(p2), _p3(p3) {}

    Point get_p1() const {
        return _p1;
    }

    Point get_p2() const {
        return _p2;
    }

    Point get_p3() const {
        return _p3;
    }

    bool contains(const Point& p) const {
        
        auto s = (_p1.get_x() - _p3.get_x()) * (p.get_y() - _p3.get_y()) - (_p1.get_y() - _p3.get_y()) * (p.get_x() - _p3.get_x());
        auto t = (_p2.get_x() - _p1.get_x()) * (p.get_y() - _p1.get_y()) - (_p2.get_y() - _p1.get_y()) * (p.get_x() - _p1.get_x());

        if ((s < 0) != (t < 0) && s != 0 && t != 0) {
            return false;
        }

        auto d = (_p3.get_x() - _p2.get_x()) * (p.get_y() - _p2.get_y()) - (_p3.get_y() - _p2.get_y()) * (p.get_x() - _p2.get_x());
        return d == 0 || (d < 0) == (s + t <= 0);
    }
};

inline bool operator==(const Triangle& t1, const Triangle& t2) {
    return (t1.get_p1() == t2.get_p1())
        && (t1.get_p2() == t2.get_p2())
        && (t1.get_p3() == t2.get_p3());
}

inline bool operator!=(const Triangle& t1, const Triangle& t2) {
    return !(t1 == t2);
}

inline std::ostream& operator<<(std::ostream& stream, const Triangle& triangle) {
    return stream << '{' << triangle.get_p1() << ", " << triangle.get_p2()
        << ", " << triangle.get_p3() << '}';
}

} // namespace aac

#endif // TRIANGLE_HPP
