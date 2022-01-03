#include <BiggetRectangleInHistogram/biggestRectangleInHistogram.hpp>
#include <algorithm>
#include <iostream>

namespace aac
{
    double biggestRectangleIterators(const std::vector<double> & histo) {
        double area = 0.;

        std::vector<double>::const_iterator it1 = histo.begin();
        std::vector<double>::const_iterator it2 = histo.end() - 1;

        while(it1 != it2) {
            area = std::max(area, (it2-it1) * std::min(*it1, *it2));
            if (*it1 <= *it2) {
                it1++;
            }
            else {
                it2--;
            }
        }

        return area;
    }

    double biggestRectangle(const std::vector<double> & histo) {
        double area = 0.;

        int i = 0;
        int j = histo.size() - 1;

        while(i < j) {
            area = std::max(area, (j-i) * std::min(histo[i], histo[j]));
            if (histo[i] <= histo[j]) {
                i++;
            }
            else {
                j--;
            }
        }

        return area;
    }
} // namespace aac

int main() {
    std::vector<double> v1 = {1,8,6,2,5,4,8,3,7};
    std::vector<double> v2 = {1,1};

    std::cout << aac::biggestRectangle(v1) << std::endl;
    std::cout << aac::biggestRectangle(v2) << std::endl;
}