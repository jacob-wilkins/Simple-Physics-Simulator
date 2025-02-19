#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode({1920u, 1080u}), "SFML works!");
    window.setPosition({0, 0});
    window.setVerticalSyncEnabled(true); // call it once after creating the window
    window.setFramerateLimit(60); // call it once after creating the window

    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }
}