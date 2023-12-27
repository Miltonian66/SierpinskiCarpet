#include <chrono>
#include <thread>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

const int DEFAULT_DEPTH = 5;

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 800;

const sf::Color BACKGROUND_COLOR = sf::Color::White;
const sf::Color RECTANGLE_COLOR = sf::Color::Black;

const int64_t SLEEP_BEFORE_DRAW = 500;

sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT, 32), "Hello World - SFML");

void DrawRectangle(float x1, float y1, float x2, float y2) {
    std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_BEFORE_DRAW));
    sf::RectangleShape rect;
    rect.setSize({x2 - x1, y2 - y1});
    rect.setPosition({x1, y1});
    rect.setFillColor(RECTANGLE_COLOR);

    window.draw(rect);
    window.display();
}


void SierpinskiCarpet(float x1, float y1, float x2, float y2, int depth) {
    if (depth <= 0)
        return;

    float x1n = 2 * x1 / 3 + x2 / 3,
          y1n = 2 * y1 / 3 + y2 / 3,
          x2n = x1 / 3 + 2 * x2 / 3,
          y2n = y1 / 3 + 2 * y2 / 3;

    DrawRectangle(x1n, y1n, x2n, y2n);

    depth--;

    SierpinskiCarpet(x1, y1, x1n, y1n, depth);
    SierpinskiCarpet(x1n, y1, x2n, y1n, depth);
    SierpinskiCarpet(x2n, y1, x2, y1n, depth);
    SierpinskiCarpet(x1, y1n, x1n, y2n,  depth);
    SierpinskiCarpet(x2n, y1n, x2, y2n, depth);
    SierpinskiCarpet(x1, y2n, x1n, y2, depth);
    SierpinskiCarpet(x1n, y2n, x2n, y2, depth);
    SierpinskiCarpet(x2n, y2n, x2, y2, depth);
}

int main() {
    window.clear(BACKGROUND_COLOR);
    //DrawRectangle(200, 300, 400, 400);
    SierpinskiCarpet(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, 3);

    while (true) {
        sf::Event event{};
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }
    return 0;
}
