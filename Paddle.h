#pragma once
#include <SFML/Graphics.hpp>
#include <IoStream>

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

    const sf::RectangleShape& get() const
    {
        return paddle;
    };

    void move(float dy, int windowHeight)
    {
        //std::cout << paddle.getPosition().y << std::endl;
        paddle.move(0, dy);
        if (paddle.getPosition().y < 0 || paddle.getPosition().y > windowHeight - paddle.getSize().y)
            paddle.move(0, -dy);
    }
};

