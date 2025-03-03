#include <vector>
#include <cmath>
#include <SFML/Graphics.hpp>
#include "verlet.hpp"

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

            Verlet verlet(circle, gravity);

            objects.push_back(verlet);
        }

        const std::vector<Verlet>& getCircles() const {
            return objects;
        }

        void removeCircles() {
            objects.clear();
        }

        sf::Vector2f getGravity() {
            return gravity;
        }

    private:
        std::vector<Verlet> objects;
        sf::RenderWindow& window;
        sf::Vector2u bounds = window.getSize();
        sf::Vector2f gravity = {0.0f, 9.8f};

        void addGravity(){
            for (auto& object : objects) {
                object.update();
            }
        }

        void checkBounds() {
            for (auto& object : objects) {
                sf::Vector2f position = object.getCircle().getPosition();
                float radius = object.getCircle().getRadius();

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

                object.setOldPosition(object.getPosition());
                object.getCircle().move(position);
                object.setPosition(position);
            }
        }
};