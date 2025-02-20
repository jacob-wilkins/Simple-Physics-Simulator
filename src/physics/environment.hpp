#include <vector>
#include <cmath>
#include <SFML/Graphics.hpp>

class Environment {
    public:
        Environment() = default;

        Environment(sf::RenderWindow& window) : window{window} {}

        void addCircle(float radius, sf::Vector2f pos, sf::Color color) {
            sf::CircleShape circle(radius);
            circle.setPosition(pos);
            circle.setFillColor(color);
            objects.push_back(circle);
        }

        const std::vector<sf::CircleShape>& getCircles() const {
            return objects;
        }

        void update() {
            // update the positions of all objects
            // gravity, acceleration, position, etc

            addGravity();
        }

    private:
        std::vector<sf::CircleShape> objects;
        sf::RenderWindow& window;
        sf::Vector2u bounds = window.getSize();
        sf::Vector2f gravity = {0, 19.6};

        void addGravity(){
            for (auto& object : objects) {
                object.move(gravity);
            }
        }
};