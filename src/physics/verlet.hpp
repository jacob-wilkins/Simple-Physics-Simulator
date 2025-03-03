#include <vector>
#include <cmath>
#include <SFML/Graphics.hpp>

class Verlet {
    public:
        Verlet() = default;

        Verlet(sf::CircleShape circle, sf::Vector2f gravity) : circle{circle}, position{circle.getPosition()}, oldPosition{circle.getPosition()}, gravity{gravity} {}

        sf::CircleShape getCircle() const {
            return circle;
        }

        sf::Vector2f getPosition() {
            return position;
        }

        void setPosition(sf::Vector2f pos) {
            position = pos;
        }

        void setOldPosition(sf::Vector2f pos) {
            oldPosition = pos;
        }

        sf::Vector2f getVelocity() {
            return velocity;
        }

        void addVelocity(sf::Vector2f vel) {
            velocity += vel;

            if (velocity.y > 55.0f) {
                velocity.y = 55.0f;
            }
        }

        void update() {
            // update the positions of all objects
            // gravity, acceleration, position, etc
            addVelocity(gravity);
            checkBounds(); // TODO
            oldPosition = position;
            circle.move(velocity);
            position = circle.getPosition();
        }

    private:
        sf::CircleShape circle;
        sf::Vector2f position;
        sf::Vector2f oldPosition;
        sf::Vector2f acceleration;
        sf::Vector2f velocity;
        sf::Vector2f gravity;
};