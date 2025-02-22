#include <vector>
#include <cmath>
#include <SFML/Graphics.hpp>

class Verlet {
    public:
        Verlet() = default;

        Verlet(sf::CircleShape circle) : circle{circle}, position{circle.getPosition()}, oldPosition{circle.getPosition()} {}

        sf::Vector2f getPosition() {
            return position;
        }

        void setPosition(sf::Vector2f pos) {
            position = pos;
        }

        sf::Vector2f getVelocity() {
            return velocity;
        }

        void setVelocity(sf::Vector2f vel) {
            velocity = vel;
        }

    private:
        sf::CircleShape circle;
        sf::Vector2f position;
        sf::Vector2f oldPosition;
        sf::Vector2f acceleration;
        sf::Vector2f velocity;
}