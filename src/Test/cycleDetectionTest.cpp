#include <CycleDetection/cycleDetection.hpp>
#include <Catch/catch.hpp>
#include <iostream>
#include <vector>


TEST_CASE ( "Trivial function" ) {

    std::vector<int> vec = {1,2,3,4,5,6,4};
    std::function<int(int)> f = [&](int a) {
        return vec[a];
    };

    REQUIRE ( aac::brent<int>(f, 0) ==  std::pair<int, int>(3,4) );
}