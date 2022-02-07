#include <array>
#include <algorithm>
#include <random>
#include <iostream>
#include <sstream>
#include <Delaunay/delaunay.hpp>
#include <SFML/Graphics.hpp>

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;
const int DELTA = 5;
const int WINDOW_DELTA = 50;
const int POINT_RADIUS = 4;

using bounds_t = std::array<double, 4>;
int get_scaled_x(double x, const bounds_t& bounds) {
    return WINDOW_WIDTH * ((x - bounds[0]) / (float)(bounds[2] - bounds[0]));
}

int get_scaled_y(double y, const bounds_t & bounds) {
    return WINDOW_HEIGHT * ((y - bounds[1]) / (float)(bounds[3] - bounds[1]));
}

void draw_point_label(sf::RenderWindow& window, const sf::Font& font, double x, double y, const bounds_t& bounds) {
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

void draw_line(sf::RenderWindow& window, double x0, double y0, double x1, double y1, const bounds_t& bounds, sf::Color color = sf::Color::Black) {
    sf::VertexArray line(sf::LinesStrip, 2);
    line[0].position = sf::Vector2f(get_scaled_x(x0, bounds) + POINT_RADIUS, get_scaled_y(y0, bounds) + POINT_RADIUS);
    line[0].color = color;
    line[1].position = sf::Vector2f(get_scaled_x(x1, bounds) + POINT_RADIUS, get_scaled_y(y1, bounds) + POINT_RADIUS);
    line[1].color = color;

    window.draw(line);
}

void draw_triangle(sf::RenderWindow& window, const aac::Triangle& triangle, const bounds_t& bounds) {
    draw_line(window, triangle.get_p1().get_x(), triangle.get_p1().get_y(), triangle.get_p2().get_x(), triangle.get_p2().get_y(), bounds);
    draw_line(window, triangle.get_p2().get_x(), triangle.get_p2().get_y(), triangle.get_p3().get_x(), triangle.get_p3().get_y(), bounds);
    draw_line(window, triangle.get_p1().get_x(), triangle.get_p1().get_y(), triangle.get_p3().get_x(), triangle.get_p3().get_y(), bounds);
}

void draw_point(sf::RenderWindow& window, double x, double y, const bounds_t& bounds, sf::Color color = sf::Color::Red) {
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
const bounds_t get_bounds(const std::vector<aac::Point>& points) {
    bounds_t bounds{};

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

void draw_points(sf::RenderWindow& window, const sf::Font& font, const std::vector<aac::Point>& points, const std::vector<aac::Triangle>& triangles, bounds_t& bounds) {
    for (const auto& point : points) {
        auto color = sf::Color::Red;
        draw_point(window, point.get_x(), point.get_y(), bounds, color);
        draw_point_label(window, font, point.get_x(), point.get_y(), bounds);
    }
    for (const auto& triangle : triangles) {
        draw_triangle(window, triangle, bounds);
    }
}

int main() {
    std::vector<aac::Point> points;
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(
        sf::VideoMode(WINDOW_WIDTH + WINDOW_DELTA, WINDOW_HEIGHT + WINDOW_DELTA),
        "Delaunay triangulation",
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

    auto bounds = get_bounds(points);
    aac::DelaunayTriangulation triangulation(points);
    auto triangles = triangulation.evaluate();


    while (window.isOpen()) {
        sf::Event event;

        draw_plane(window);
        draw_points(window, font, points, triangles, bounds);

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.display();
    }

    return EXIT_SUCCESS;
}