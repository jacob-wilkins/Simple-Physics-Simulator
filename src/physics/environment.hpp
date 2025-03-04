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
            removeDisappearedCircles();
        }

        void addCircle(float radius, sf::Vector2f pos, sf::Color color) {
            sf::CircleShape circle(radius);
            circle.setPosition(pos);
            circle.setFillColor(color);

            Verlet verlet(circle, gravity, bounds);

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

        sf::Vector2u getBounds() {
            return bounds;
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

                // save old position
                object.setOldPosition(position);

                // when radius collides with bounds, reverse the velocity
                if (position.x - radius < 0 || position.x + radius > bounds.x) {
                    object.addVelocity({-object.getVelocity().x, 0.0f});
                }

                if (position.y - radius < 0 || position.y + radius > bounds.y) {
                    object.addVelocity({0.0f, -object.getVelocity().y});
                }
            }
        }

        void removeDisappearedCircles() {
            for (auto& object: objects) {
                sf::Vector2f position = object.getCircle().getPosition();
                float radius = object.getCircle().getRadius();

                if (position.y + radius > bounds.y) {
                    objects.erase(objects.begin());
                }
            }
        }
};