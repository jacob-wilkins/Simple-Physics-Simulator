#include <vector>
#include <cmath>
#include <SFML/Graphics.hpp>

class Verlet {
    public:
        Verlet() = default;

        Verlet(sf::CircleShape circle, sf::Vector2f gravity, sf::Vector2u bounds) : 
            circle{circle}, position{circle.getPosition()}, oldPosition{circle.getPosition()}, gravity{gravity}, bounds{bounds} {}

        sf::CircleShape getCircle() const {
            return circle;
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
            checkBounds(bounds);

            printf("Velocity: %f, %f\n", velocity.x, velocity.y);

            oldPosition = position;
            circle.move(velocity);
        }

        void checkBounds(sf::Vector2u bounds) {
            if (position.x < 0 || position.x > bounds.x) {
                velocity.x *= -0.7;
            }

            if (position.y < 0 || position.y > bounds.y) {
                velocity.y *= -0.5;
            }
        }

    private:
        sf::CircleShape circle;
        sf::Vector2f position;
        sf::Vector2f oldPosition;
        sf::Vector2f acceleration;
        sf::Vector2f velocity;
        sf::Vector2f gravity;
        sf::Vector2u bounds;
};