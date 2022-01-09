#include <LinearEquationSystem/linearEquation.hpp>
#include <iostream>
#include <cmath>

Solver::Solver(const std::vector<std::vector<double>> & A, const std::vector<double> & B) :
 A(A), X(std::vector<double>(A[0].size())), B(B), size(A[0].size()) {

 }

int Solver::FindPivot(int column) const {
    double max = -1;
    int line = column;

    for(int i=column; i< size; i++) {
        if (fabs(A[i][column]) > max) {
            max = fabs(A[i][column]);
            line = i;
        }
    }

    return line;
}

void Solver::SwapLines(int i, int j) {
    A[i].swap(A[j]);
    std::swap(B[i], B[j]);
}

void Solver::NormalizePivotElement(int line) {
    double norm = 1./A[line][line];

    for(double & coeff : A[line]) {
        coeff *= norm;
    }

    B[line] *= norm;
}

void Solver::VarElimination(int column) {
    double coeff;
    for(int i=column + 1; i<size; i++) {
        coeff = A[i][column];
        for(int j=column; j< size; j++) {
            A[i][j] -= coeff*A[column][j];
        }
        B[i] -= coeff*B[column];
    }
}

void Solver::BackSubstitution() {
    double sum;

    for(int i=size-1; i>=0; i--) {
        sum = B[i];
        for(int j=i+1; j<size;j++) {
            sum -= A[i][j]*X[j];
        }
        X[i] = sum/A[i][i];
    }
}

const std::vector<double> & Solver::Solve() {
    int pivot = 0;

    for(int i=0; i<size;i++) {
        pivot = FindPivot(i);
        SwapLines(i,pivot);
        NormalizePivotElement(i);
        VarElimination(i);
    }

    BackSubstitution();

    return X;
}

std::ostream & operator<<(std::ostream & o, const Solver &s) {
    for(double d : s.getSolution()) {
        o << d << " ";
    }

    o << std::endl;

    return o;
}

// int main() {

//     std::vector<std::vector<double>> A = {
//         {1,1,1},
//         {1,-1,1},
//         {2,-1,3}
//     };

//     std::vector<double> B = {6,2,9};

//     Solver s(A,B);

//     std::vector<std::vector<double>> A2 = {
//         {1,1},
//         {1,-1}
//     };

//     std::vector<double> B2 = {5,1};

//     std::vector<std::vector<double>> A3 = {
//         {1,1,2,3},
//         {1,-1,3,-2},
//         {2,3,1,0},
//         {1,1,1,1}
//     };

//     std::vector<double> B3 = {5,1,2,1};

//     std::vector<std::vector<double>> A4 = {
//         {1,1},
//         {-1,-1}
//     };

//     std::vector<double> B4 = {1,2};

//     s.Solve();
//     std::cout << s;

//     s = Solver(A2,B2);
//     s.Solve();
//     std::cout << s;

//     s = Solver(A3,B3);
//     s.Solve();
//     std::cout << s;

//     s = Solver(A4,B4);
//     s.Solve();
//     std::cout << s;
    
//     return 0;
// }