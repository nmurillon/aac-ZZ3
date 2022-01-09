#pragma once

#include <vector>
#include <algorithm>
#include <ostream>

class Solver {
    private:
    /* We are going to solve AX=B */
        std::vector<std::vector<double>> A;
        std::vector<double> X;
        std::vector<double> B;
        int size;
    
    private:
        int FindPivot(int column)const;
        void SwapLines(int i, int j);
        void NormalizePivotElement(int line);
        void VarElimination(int column);
        void BackSubstitution();

    public:
        Solver(const std::vector<std::vector<double>> &, const std::vector<double> &);
        const std::vector<double> & Solve();
        inline int getDimension() const { return size;};
        inline const std::vector<double> & getSolution() const { return X;};
};

std::ostream & operator<<(std::ostream & o, const Solver &s) {
    for(double d : s.getSolution()) {
        o << d << " ";
    }

    o << std::endl;

    return o;
}