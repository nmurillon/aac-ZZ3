#include <Delaunay/delaunay.hpp>
#include <Catch/catch.hpp>
#include <iostream>
#include <vector>

TEST_CASE("Trivial case : 3 points") {
	aac::DelaunayTriangulation triangulation(std::vector<aac::Point>{
		aac::Point(0,0),
		aac::Point(1,1),
		aac::Point(0,1)
	});

	std::vector<aac::Triangle> expected = std::vector<aac::Triangle>{ aac::Triangle(aac::Point(0, 0), aac::Point(1, 1), aac::Point(0, 1)) };
	std::vector<aac::Triangle> res = triangulation.evaluate();
	std::string str;

	REQUIRE(res == expected);
}