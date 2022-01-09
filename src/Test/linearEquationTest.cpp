#include <LinearEquationSystem/linearEquation.hpp>
#include <Catch/catch.hpp>

TEST_CASE ( "2x2 system" ) {
    std::vector<std::vector<double>> A = {
        {1,1},
        {1,-1}
    };

    std::vector<double> B = {5,1};
    std::vector<double> solution = {3,2};
    Solver s(A,B);

    REQUIRE (s.Solve() == solution);
}

TEST_CASE ( "3x3 system" ) {
    std::vector<std::vector<double>> A = {
        {1,1,1},
        {1,-1,1},
        {2,-1,3}
    };

    std::vector<double> B = {6,2,9};

    std::vector<double> solution = {1,2,3};
    Solver s(A,B);
    
    REQUIRE (s.Solve() == solution);
}

TEST_CASE ( "4x4 system" ) {
    std::vector<std::vector<double>> A = {
        {1,1,2,3},
        {1,-1,3,-2},
        {2,3,1,0},
        {1,1,1,1}
    };

    std::vector<double> B = {5,1,2,1};

    std::vector<double> solution = {-7,4,4,0};
    Solver s(A,B);
    
    REQUIRE (s.Solve() == solution);
}

