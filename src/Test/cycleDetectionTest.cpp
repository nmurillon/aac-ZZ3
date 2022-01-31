#include <CycleDetection/cycleDetection.hpp>
#include <Catch/catch.hpp>
#include <iostream>
#include <vector>


TEST_CASE ( "Trivial function" ) {

    std::vector<int> vec = {1,2,3,4,5,6,4};
    std::function f = [&vec](int a) {
        return vec[a];
    };

    REQUIRE ( aac::brent(f, 0) ==  std::pair(3,4) );
}

TEST_CASE( "Collatz conjecture" ) {

    std::function f = [](int a) {
        if (a % 2 == 0) {
            return a / 2;
        }
        else {
            return 3 * a + 1;
        }
    };

    for (int i = 0; i < 50; ++i) {
        auto [length, outside] = aac::brent(f, i * 50 + 1);
        REQUIRE(length == 3); // 4, 2, 1, ...
    }
}

TEST_CASE( "One long cycle ") {

    std::function f = [&](int a) {
        return (a + 1) % 0xFFFA;
    };

    auto [length, outside] = aac::brent(f, 0);
    REQUIRE(length == 0xFFFA);
    REQUIRE(outside == 0); // Nothing not belonging to the cycle
}

TEST_CASE( "Instant cycle" ) {
    std::function f = [&](int a) {
        return 0;
    };

    auto [length, outside] = aac::brent(f, 0);
    REQUIRE(length == 1);
    REQUIRE(outside == 0);
}
