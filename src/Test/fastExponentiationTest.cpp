#include <FastExponentiation/fastExponentiation.hpp>
#include <Catch/catch.hpp>

TEST_CASE ( "Simple test" ) {
    REQUIRE(aac::fastExponentiation(2,3) == 8 );
}

// int main() {
//     std::cout << aac::fastExponentiation(8,6) << std::endl;
//     std::cout << aac::fastExponentiation(2,15) << std::endl;
//     std::cout << aac::fastExponentiation(2,16) << std::endl;
//     std::cout << aac::fastExponentiation(2,-16) << std::endl;
//     return 0;
// }