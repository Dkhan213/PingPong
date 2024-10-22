#include <SFML/Graphics.hpp>

class Paddle
{
private:
    sf::RectangleShape paddle;
public:
    Paddle(float x, float y)
    {
        paddle.setSize(sf::Vector2f(10, 100));
        paddle.setPosition(x, y);
        paddle.setFillColor(sf::Color::White);
    }

    sf::RectangleShape getShape() const 
    {
        return paddle;
    };
};

const int windowWidth = 800;
const int windowHeight = 600;

int main() {
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Window");

    Paddle leftPaddle(10, windowHeight / 2 - 50);
    Paddle rightPaddle(windowWidth - 20, windowHeight / 2 - 50);

    // Game loop
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        // Clear and draw
        window.clear();
        window.draw(leftPaddle.getShape());
        window.draw(rightPaddle.getShape());
        window.display();
    }
    return 0;
}
