#include <BiggetRectangleInHistogram/biggestRectangleInHistogram.hpp>
#include <Catch/catch.hpp>

TEST_CASE ( "Simple test" ) {
    REQUIRE(aac::biggestRectangle({ 1 }) == 0);
}

TEST_CASE("Two classes cases") {
    REQUIRE(aac::biggestRectangle({ 1, 1 }) == 1);
    REQUIRE(aac::biggestRectangle({ 2, 4 }) == 2);
    REQUIRE(aac::biggestRectangle({ 5, 4 }) == 4);
}

TEST_CASE("Negative values") {
    REQUIRE(aac::biggestRectangle({ -1, -2 }) == 0);
    REQUIRE(aac::biggestRectangle({ 1, 1, 0, -8, 1 }) == 4);
}

TEST_CASE("Null values") {
    REQUIRE(aac::biggestRectangle({ 0, 0, 0, 0 }) == 0);
}

TEST_CASE("Same value") {
    REQUIRE(aac::biggestRectangle({ 6, 6, 6, 6, 6, 6, 6, 6 }) == 42);
}

TEST_CASE("Non-trivial Cases") {
    REQUIRE(aac::biggestRectangle({ 0, 2, 0, 0, 1 }) == 3);
    REQUIRE(aac::biggestRectangle({ 1, 8, 6, 2, 5, 4, 8, 3, 7 }) == 49);
    REQUIRE(aac::biggestRectangle({ 4, 2, 12, 21, 0, 3, 16, 9, 10 }) == 60);
    REQUIRE(aac::biggestRectangle({ 9, 17, 1, 4, 40, 40, 10 }) == 68);
}
