#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

const int windowWidth = 800;
const int windowHeight = 600;

int main() {
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Window");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Clear and draw
        window.clear();
        window.display();
    }



    return 0;
}
