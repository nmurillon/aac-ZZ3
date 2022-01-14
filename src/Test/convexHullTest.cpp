#include <ConvexHull/convex_hull.hpp>
#include <Geometry/orientation.hpp>
#include <Geometry/point.hpp>
#include <Catch/catch.hpp>

TEST_CASE ( "Less than 3 points" ) {

    std::vector<aac::Point> points = {
        aac::Point(0,1),
        aac::Point(0,2)
    };

    REQUIRE( aac::jarvis_march(points) == std::vector<aac::Point>() );
}

TEST_CASE( "Trivial Case Triangle" ) {
    std::vector<aac::Point> points = {
        aac::Point(0,0),
        aac::Point(2,0),
        aac::Point(1,2),
        aac::Point(1,1)
    };

    std::vector<aac::Point> hull = {
        aac::Point(0,0),
        aac::Point(1,2),
        aac::Point(2,0)
    };

    REQUIRE(aac::jarvis_march(points) == hull);
}

TEST_CASE("Trivial Case Rectangle") {
    std::vector<aac::Point> points = {
        aac::Point(0,0),
        aac::Point(2,0),
        aac::Point(2,2),
        aac::Point(0,2),
        aac::Point(1,1.2),
        aac::Point(0.5,1)
    };

    std::vector<aac::Point> hull = {
        aac::Point(0,0),
        aac::Point(0,2),
        aac::Point(2,2),
        aac::Point(2,0)
    };

    REQUIRE(aac::jarvis_march(points) == hull);
}

TEST_CASE("Non Trivial Case") {
    std::vector<aac::Point> points = {
        aac::Point(0,0),
        aac::Point(2,5),
        aac::Point(2.2,5),
        aac::Point(0,2),
        aac::Point(1,0.5),
        aac::Point(0.5,1.5)
    };

    std::vector<aac::Point> hull = {
        aac::Point(0,0),
        aac::Point(0,2),
        aac::Point(2,5),
        aac::Point(2.2,5),
        aac::Point(1,0.5)
    };

    REQUIRE(aac::jarvis_march(points) == hull);
}

TEST_CASE("Non Trivial Case 2") {
    std::vector<aac::Point> points = {
        aac::Point(-5,10),
        aac::Point(3,-2),
        aac::Point(-2.2,2),
        aac::Point(0,2),
        aac::Point(1,0.5),
        aac::Point(-0.5,1.5)
    };

    std::vector<aac::Point> hull = {
        aac::Point(-5,10),
        aac::Point(3,-2),
        aac::Point(-2.2,2)
    };

    REQUIRE(aac::jarvis_march(points) == hull);
}