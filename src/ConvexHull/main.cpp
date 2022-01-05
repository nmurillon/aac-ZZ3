#include <SFML/Graphics.hpp>
#include <ConvexHull/convex_hull.hpp>
#include <Geometry/point.hpp>

void draw_point(sf::RenderWindow& window, unsigned x, unsigned y, sf::Color color = sf::Color::Red) {
    auto circleShape = sf::CircleShape(5);
    auto size = window.getSize();
    circleShape.setFillColor(color);
    circleShape.setOrigin(x, y);
    window.draw(circleShape);
}

int main() {
    const std::vector<aac::Point> points({
        {3, 2},
        {1, 2},
        {-2, 2},
        {-1, -3.1},
        {1, 0},
        {-1.2, 2.5},
        {0, -0.7},
        {-0.5, 1},
        {0.5, -1},
    });
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(
        sf::VideoMode(800, 600),
        "Jarvis March",
        sf::Style::Default,
        settings
    );
    auto convex_hull = aac::jarvis_march(points); 

    for(const auto& point : convex_hull) {
        draw_point(window, point.get_x(), point.get_y());
    }
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.display();
    }

    return 0;
}
