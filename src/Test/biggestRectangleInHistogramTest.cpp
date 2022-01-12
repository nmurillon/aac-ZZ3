#include <BiggetRectangleInHistogram/biggestRectangleInHistogram.hpp>
#include <Catch/catch.hpp>

TEST_CASE ( "Simple test" ) {
    REQUIRE(aac::biggestRectangle(std::vector<double>{1}) == 0);
}

// int main() {
//     std::vector<double> v1 = {1,8,6,2,5,4,8,3,7};
//     std::vector<double> v2 = {1,1};

//     std::cout << aac::biggestRectangle(v1) << std::endl;
//     std::cout << aac::biggestRectangle(v2) << std::endl;
// }