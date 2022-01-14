#include <FastExponentiation/fastExponentiation.hpp>
#include <Catch/catch.hpp>
#include <cmath>

TEST_CASE("Simple cases") {
    REQUIRE(aac::fastExponentiation(2, 3) == 8);
    REQUIRE(aac::fastExponentiation(4, 5) == 1024);
    REQUIRE(aac::fastExponentiation(7, 2) == 49);
}

TEST_CASE("Pow = 1 case") {
    REQUIRE(aac::fastExponentiation(0, 1) == 0);
    REQUIRE(aac::fastExponentiation(1, 1) == 1);
    REQUIRE(aac::fastExponentiation(6, 1) == 6);
    REQUIRE(aac::fastExponentiation(12, 1) == 12);
}

TEST_CASE("Pow = 0 case") {
    REQUIRE(aac::fastExponentiation(0, 0) == 1);
    REQUIRE(aac::fastExponentiation(1, 0) == 1);
    REQUIRE(aac::fastExponentiation(2, 0) == 1);
    REQUIRE(aac::fastExponentiation(-1, 0) == 1);
}

TEST_CASE("Negative power") {
    REQUIRE(aac::fastExponentiation(2, -16) == Approx(1.5258789e-5));
    REQUIRE(aac::fastExponentiation(2, -2) == Approx(0.25));
    REQUIRE(aac::fastExponentiation(7, -4) == Approx(0.000416493128));
}

// int main() {
//     std::cout << aac::fastExponentiation(8,6) << std::endl;
//     std::cout << aac::fastExponentiation(2,15) << std::endl;
//     std::cout << aac::fastExponentiation(2,16) << std::endl;
//     std::cout << aac::fastExponentiation(2,-16) << std::endl;
//     return 0;
// }