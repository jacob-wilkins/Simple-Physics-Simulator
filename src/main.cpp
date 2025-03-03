#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "physics/environment.hpp"

using namespace std;

int main()
{
    sf::ContextSettings settings;
    settings.antiAliasingLevel = 1;

    sf::RenderWindow window(sf::VideoMode({1920u, 1080u}), "Simple Physics Simulator");

    window.setPosition({0, 0});
    window.setVerticalSyncEnabled(true); // call it once after creating the window
    window.setFramerateLimit(60); // call it once after creating the window

    Environment env(window);
    env.addCircle(100.0f, {static_cast<float>(window.getSize().x / 2 - 100), static_cast<float>(window.getSize().y / 2 - 100)}, sf::Color::White);

    while (window.isOpen())
    {
        while (const optional event = window.pollEvent())
        {
            // close button on the window
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }

            // click left mouse button to add a circle
            // very fast at the moment, need to change in the future
            if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
                env.addCircle(50.0f, static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)), sf::Color::White);
            }

            // press D to remove all circles in the window
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
                env.removeCircles();
            }
        }

        window.clear();

        env.update();

        // Draw all circles in the environment
        for (const auto& circle : env.getCircles()) {
            window.draw(circle.getCircle());
        }

        window.display();
    }
}