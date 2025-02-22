#include <vector>
#include <cmath>
#include <SFML/Graphics.hpp>

// TODO:
// make new object to hold the velocity and other physics properties of an object
// maybe use verlet integreation or another algorithm to calculate the physics

class Environment {
    public:
        Environment() = default;

        Environment(sf::RenderWindow& window) : window{window} {}

        void update() {
            // update the positions of all objects
            // gravity, acceleration, position, etc

            addGravity();
            checkBounds();
        }

        void addCircle(float radius, sf::Vector2f pos, sf::Color color) {
            sf::CircleShape circle(radius);
            circle.setPosition(pos);
            circle.setFillColor(color);
            objects.push_back(circle);
        }

        const std::vector<sf::CircleShape>& getCircles() const {
            return objects;
        }

    private:
        std::vector<sf::CircleShape> objects;
        sf::RenderWindow& window;
        sf::Vector2u bounds = window.getSize();
        sf::Vector2f gravity = {0.0f, 9.8f};

        void addGravity(){
            for (auto& object : objects) {
                object.move(gravity);
            }
        }

        void checkBounds() {
            for (auto& object : objects) {
                sf::Vector2f position = object.getPosition();
                float radius = object.getRadius();

                // Check left and right bounds
                if (position.x < 0) {
                    position.x = 0;
                } else if (position.x + 2 * radius > bounds.x) {
                    position.x = bounds.x - 2 * radius;
                }

                // Check top and bottom bounds
                if (position.y < 0) {
                    position.y = 0;
                } else if (position.y + 2 * radius > bounds.y) {
                    position.y = bounds.y - 2 * radius;
                }

                object.setPosition(position);
            }
        }
};