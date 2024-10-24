#include "Paddle.h"

// Constructor implementation
Paddle::Paddle(float x, float y, int windowHeight) : windowHeight(windowHeight) {
    paddle.setSize(sf::Vector2f(10, 100));
    paddle.setPosition(x, y);
    paddle.setFillColor(sf::Color::White);
}

// Getter implementation
const sf::RectangleShape& Paddle::get() const {
    return paddle;
}

// Move implementation
void Paddle::move(float dy, int windowHeight) {
    paddle.move(0, dy);

    // Check boundaries
    if (paddle.getPosition().y < -10 || paddle.getPosition().y > windowHeight - paddle.getSize().y + 5) {
        paddle.move(0, -dy);  // Move back to stay within bounds
    }
}

void Paddle::setWindowHeight(int windowHeight) {
    windowHeight = windowHeight;
}