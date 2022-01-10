#include <BiggetRectangleInHistogram/biggestRectangleInHistogram.hpp>
#include <algorithm>
#include <iostream>

namespace aac
{
    /**
     * Compute the area of the biggest rectangle in a given histogram using 
     * iterators
     * @param histo a vector of double containing the value for each class
     * of the histogram. We consider that on the abscissa, each class are
     * separated by one unit
     */ 
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

    /**
     * Compute the area of the biggest rectangle in a given histogram using 
     * indexes
     * @param histo a vector of double containing the value for each class
     * of the histogram. We consider that on the abscissa, each class are
     * separated by one unit
     */ 
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