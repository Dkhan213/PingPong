#include <SFML/Graphics.hpp>
#include "Paddle.h"
#include "Ball.h"
#include <Iostream>

const int windowWidth = 800;
const int windowHeight = 600;
const float basePaddleSpeed = 450.0f;
const float targetFPS = 80.0f; // Target FPS for scaling
const float baseBallVelocity = 300.0f;

int main() {

    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Window");

    window.setFramerateLimit(targetFPS); // Set FPS Limit
    window.setVerticalSyncEnabled(true);

    Paddle leftPaddle(10, windowHeight / 2 - 50, windowHeight); // Create left paddle object
    Paddle rightPaddle(windowWidth - 20, windowHeight / 2 - 50, windowHeight); //Create right paddle object
    Ball ball(windowWidth / 2 - 10, windowHeight, baseBallVelocity); // Create ball object

    sf::Clock fpsClock; // Create a clock to track FPS
    int frameCount = 0; // Frame counter
    float fps = 0.0f; // FPS value

    sf::Clock clock;
    sf::Time time;
    float dt = 0;

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
            //std::cout << "FPS: " << fps << std::endl; // Print FPS to console
        }

        float paddleSpeed = basePaddleSpeed * dt;
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

            ball.move(dt);
            ball.collisionDetection(leftPaddle, rightPaddle);

            time = clock.restart();
            dt = time.asSeconds();

        // Clear and draw
        window.clear();
        window.draw(leftPaddle.get());
        window.draw(rightPaddle.get());
        window.draw(ball.get());
        window.display();

    }
    return 0;
}