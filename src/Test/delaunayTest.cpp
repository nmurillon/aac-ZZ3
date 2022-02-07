#include <Delaunay/delaunay.hpp>
#include <Catch/catch.hpp>
#include <iostream>

TEST_CASE("Trivial case : 3 points") {
	aac::DelaunayTriangulation triangulation(std::vector<aac::Point>{
		aac::Point(0,0),
		aac::Point(1,1),
		aac::Point(0,1)
	});

	std::vector<aac::Triangle> expected = std::vector<aac::Triangle>{ aac::Triangle(aac::Point(0, 0), aac::Point(0, 1), aac::Point(1, 1)) };

	REQUIRE(triangulation.evaluate() == expected);
}

TEST_CASE("Trivial case : 4 points") {
	aac::DelaunayTriangulation triangulation(std::vector<aac::Point>{
		aac::Point(0, 0),
		aac::Point(1, 1),
		aac::Point(0, 1),
		aac::Point(0.5, 0.5)
	});

	std::vector<aac::Triangle> expected = std::vector<aac::Triangle>{
		aac::Triangle(aac::Point(0, 0), aac::Point(0.5, 0.5), aac::Point(0, 1)),
		aac::Triangle(aac::Point(0, 1), aac::Point(0.5, 0.5), aac::Point(1, 1)),
		aac::Triangle(aac::Point(0, 0), aac::Point(0.5, 0.5), aac::Point(1, 1))
	};

	REQUIRE(triangulation.evaluate() == expected);
}

TEST_CASE("Trivial case : 5 points with colinear points") {
	aac::DelaunayTriangulation triangulation(std::vector<aac::Point>{
		aac::Point(0, 0),
		aac::Point(1, 1),
		aac::Point(0, 1),
		aac::Point(1,0),
		aac::Point(0.5, 0.5)
	});

	std::vector<aac::Triangle> expected = std::vector<aac::Triangle>{
		aac::Triangle(aac::Point(0, 0), aac::Point(0.5, 0.5), aac::Point(0, 1)),
		aac::Triangle(aac::Point(0, 1), aac::Point(0.5, 0.5), aac::Point(1, 1)),
		aac::Triangle(aac::Point(0, 0), aac::Point(0.5, 0.5), aac::Point(1, 1)),
		aac::Triangle(aac::Point(0, 0), aac::Point(1, 1), aac::Point(1, 0))
	};

	REQUIRE(triangulation.evaluate() == expected);
}

TEST_CASE("Trivial case : 5 points") {
	aac::DelaunayTriangulation triangulation(std::vector<aac::Point>{
		aac::Point(0, 0),
			aac::Point(1, 1),
			aac::Point(0, 1),
			aac::Point(1, 0),
			aac::Point(0.5, 0.75)
	});

	std::vector<aac::Triangle> expected = std::vector<aac::Triangle>{
		aac::Triangle(aac::Point(0, 0), aac::Point(0.5, 0.75), aac::Point(0, 1)),
		aac::Triangle(aac::Point(0, 1), aac::Point(0.5, 0.75), aac::Point(1, 1)),
		aac::Triangle(aac::Point(0, 0), aac::Point(0.5, 0.75), aac::Point(1, 1)),
		aac::Triangle(aac::Point(0, 0), aac::Point(1, 1), aac::Point(1, 0))
	};

	REQUIRE(triangulation.evaluate() == expected);
}