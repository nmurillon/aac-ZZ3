#include <iostream>
#include <cstdlib>
#include <ConvexHull/convex_hull.hpp>

int main() {
    std::vector<aac::Point> points({
        {1, 1},
        {1, -1},
        {0, 0},
        {-1, -1},
        {-1, 1},
    });
    auto convex_hull = aac::jarvis_march(points);

    std::cout << convex_hull.size() << std::endl;
    for(const auto& point : convex_hull) {
        std::cout << point << "\n";
    }

    return EXIT_SUCCESS;
}
