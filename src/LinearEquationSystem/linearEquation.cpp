#include <LinearEquationSystem/linearEquation.hpp>
#include <iostream>
#include <cmath>
#include <exception>

Solver::Solver(const std::vector<std::vector<double>> & A, const std::vector<double> & B) :
 A(A), X(std::vector<double>(A[0].size())), B(B), size(A[0].size()) {

 }

/**
 * Searching the pivot by taking the maximum
 * coefficient with absolute value.
 * Return the index of the line where the pivot is
 * 
 * @param column the index of the column where 
 * to search the pivot
 */
int Solver::FindPivot(int column) const {
    double max = fabs(A[column][column]);
    int line = column;

    for(int i=column+1; i< size; i++) {
        if (fabs(A[i][column]) > max) {
            max = fabs(A[i][column]);
            line = i;
        }
    }

    return line;
}

/**
 * Swap content of lines i and j
 * @param i index of the first line
 * @param j index of the second line to swap
 */ 
void Solver::SwapLines(int i, int j) {
    A[i].swap(A[j]);
    std::swap(B[i], B[j]);
}

/**
 * Divide all the coefficients of the pivot line by the pivot
 * @param line the index of the line we want to normalize
 */ 
void Solver::NormalizePivotElement(int line) {
    double norm = 1./A[line][line];

    for(double & coeff : A[line]) {
        coeff *= norm;
    }

    B[line] *= norm;
}

/**
 * Eliminate a variable from equations to get a 
 * triangular system
 * @param column the column corresponding to the var
 * we want to eliminate in the other equations
 */ 
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

/**
 * Once the system is triangular, we calculate the solution
 * for each variable
 */ 
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

/**
 * Solve the system and return the solution
 * @throw std::logic_error if the system has no solution
 * or if it has an infinity of solution
 */ 
const std::vector<double> & Solver::Solve() {
    int pivot = 0;

    for(int i=0; i<size;i++) {
        pivot = FindPivot(i);
        
        if(A[pivot][pivot] == 0) {
            throw std::logic_error("The system has no solution, or there are an infinity of solution");
        }
        
        SwapLines(i,pivot);
        NormalizePivotElement(i);
        VarElimination(i);
    }

    BackSubstitution();

    return X;
}

/**
 * Print the solution to a ostream
 */
std::ostream & operator<<(std::ostream & o, const Solver &s) {
    for(double d : s.getSolution()) {
        o << d << " ";
    }

    o << std::endl;

    return o;
}