#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Paddle {

private:
    sf::RectangleShape paddle;
    const int windowHeight;

public:
    // Constructor
    Paddle(float x, float y, int windowHeight);

    // Getter for the paddle shape
    const sf::RectangleShape& get() const;

    // Method to move the paddle
    void move(float dy, int windowHeight);

    void Paddle::setWindowHeight(int windowHeight);
};