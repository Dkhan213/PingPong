#include <SFML/Graphics.hpp>
#include "Paddle.h"
#include <Iostream>

const int windowWidth = 800;
const int windowHeight = 600;
const float basePaddleSpeed = 15.0f; // Base speed
const float targetFPS = 60.0f; // Target FPS for scaling


int main() {
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Window");
    window.setFramerateLimit(60);

    Paddle leftPaddle(10, windowHeight / 2 - 50);
    Paddle rightPaddle(windowWidth - 20, windowHeight / 2 - 50);
    sf::Clock fpsClock; // Create another clock to track FPS
    int frameCount = 0; // Frame counter
    float fps = 0.0f; // FPS value

    // Game loop
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        frameCount++;
        if (fpsClock.getElapsedTime().asSeconds() >= 1.0f) {
            fps = frameCount; // Set FPS
            frameCount = 0; // Reset frame count
            fpsClock.restart(); // Restart the FPS clock
            std::cout << "FPS: " << fps << std::endl; // Print FPS to console
        }

        float paddleSpeed = basePaddleSpeed * (targetFPS / fps);
        
        //std::cout << paddleSpeed << std::endl;

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            leftPaddle.move(-paddleSpeed, windowHeight);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            leftPaddle.move(paddleSpeed, windowHeight);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            rightPaddle.move(-paddleSpeed, windowHeight);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            rightPaddle.move(paddleSpeed, windowHeight);
        }

        // Clear and draw
        window.clear();
        window.draw(leftPaddle.get());
        window.draw(rightPaddle.get());
        window.display();

    }
    return 0;
}
