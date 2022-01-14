#include <array>
#include <algorithm>
#include <random>
#include <iostream>
#include <sstream>
#include <SFML/Graphics.hpp>
#include <ConvexHull/convex_hull.hpp>
#include <Geometry/point.hpp>

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;
const int DELTA = 5;
const int WINDOW_DELTA = 50;
const int POINT_RADIUS = 4;

int get_scaled_x(int x, const std::array<int, 4>& bounds) {
    return WINDOW_WIDTH * ((x - bounds[0]) / (float)(bounds[2] - bounds[0]));
}

int get_scaled_y(int y, const std::array<int, 4>& bounds) {
    return WINDOW_HEIGHT * ((y - bounds[1]) / (float)(bounds[3] - bounds[1]));
}

void draw_point_label(sf::RenderWindow& window, const sf::Font& font, int x, int y, const std::array<int, 4>& bounds) {
    int xd = get_scaled_x(x, bounds);
    int yd = get_scaled_y(y, bounds);
    sf::Text text;
    std::stringstream ss;

    ss << "(" << x << ", " << y << ")";

    text.setFont(font);
    text.setString(ss.str());
    text.setCharacterSize(12);
    text.setColor(sf::Color::Black);
    text.setPosition(xd, yd);

    window.draw(text);
}

void draw_point(sf::RenderWindow& window, int x, int y, const std::array<int, 4>& bounds, sf::Color color = sf::Color::Red) {
    auto circleShape = sf::CircleShape(POINT_RADIUS);
    int xd = get_scaled_x(x, bounds);
    int yd = get_scaled_y(y, bounds);
    
    circleShape.setFillColor(color);
    circleShape.setPosition(xd, yd);
    window.draw(circleShape);
}

void draw_plane(sf::RenderWindow& window) {
    window.clear(sf::Color::White);
}

// x0, y0, x1, y1
std::array<int, 4> get_bounds(const std::vector<aac::Point>& points) {
    std::array<int, 4> bounds{};

    bounds[0] = (*std::min_element(points.cbegin(), points.cend(),
        [](const aac::Point& p1, const aac::Point& p2) {return p1.get_x() < p2.get_x(); })).get_x();
    bounds[1] = (*std::min_element(points.cbegin(), points.cend(),
        [](const aac::Point& p1, const aac::Point& p2) {return p1.get_y() < p2.get_y(); })).get_y();
    bounds[2] = (*std::max_element(points.cbegin(), points.cend(),
        [](const aac::Point& p1, const aac::Point& p2) {return p1.get_x() < p2.get_x(); })).get_x();
    bounds[3] = (*std::max_element(points.cbegin(), points.cend(),
        [](const aac::Point& p1, const aac::Point& p2) {return p1.get_y() < p2.get_y(); })).get_y();

    return bounds;
}

void draw_line(sf::RenderWindow& window, int x0, int y0, int x1, int y1, const std::array<int, 4>& bounds, sf::Color color = sf::Color::Black) {
    sf::VertexArray line(sf::LinesStrip, 2);
    line[0].position = sf::Vector2f(get_scaled_x(x0, bounds) + POINT_RADIUS, get_scaled_y(y0, bounds) + POINT_RADIUS);
    line[0].color = color;
    line[1].position = sf::Vector2f(get_scaled_x(x1, bounds) + POINT_RADIUS, get_scaled_y(y1, bounds) + POINT_RADIUS);
    line[1].color = color;
    
    window.draw(line);
}

void draw_points(sf::RenderWindow& window, const sf::Font& font, const std::vector<aac::Point>& points, const std::vector<aac::Point>& convex_hull, const std::array<int, 4>& bounds) {
    for (const auto& point : points) {
        auto color = sf::Color::Red;
        if (std::find(convex_hull.cbegin(), convex_hull.cend(), point) != convex_hull.end()) {
            color = sf::Color::Magenta;
        }
        draw_point(window, point.get_x(), point.get_y(), bounds, color);
        draw_point_label(window, font, point.get_x(), point.get_y(), bounds);
    }
    for (int i = 1; i < convex_hull.size() + 1; ++i) {
        draw_line(
            window,
            convex_hull[i - 1].get_x(), convex_hull[i - 1].get_y(),
            convex_hull[i % convex_hull.size()].get_x(), convex_hull[i % convex_hull.size()].get_y(),
            bounds
        );
    }
}

int main() {
    std::vector<aac::Point> points;
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(
        sf::VideoMode(WINDOW_WIDTH + WINDOW_DELTA, WINDOW_HEIGHT + WINDOW_DELTA),
        "Jarvis March",
        sf::Style::Default,
        settings
    );
    std::mt19937 rng;
    std::uniform_real_distribution<double> distribution(-50, 50);
    sf::Font font;

    if (!font.loadFromFile("./res/sansation.ttf")) {
        std::cerr << "Impossible de charger la police.\n";
        return EXIT_FAILURE;
    }

    std::generate_n(std::back_inserter(points), 25,
        [&rng, &distribution]() {
            return aac::Point(distribution(rng), distribution(rng));
        }
    );
    
    auto convex_hull = aac::jarvis_march(points);
    auto bounds = get_bounds(points);

    while (window.isOpen()) {
        sf::Event event;

        draw_plane(window);
        draw_points(window, font, points, convex_hull, bounds);

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.display();
    }

    return EXIT_SUCCESS;
}
