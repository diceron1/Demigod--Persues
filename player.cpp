#include "Player.h"
#include "iostream"

Player::Player(float x, float y) {
    shape.setPosition(x, y);
    shape.setSize(sf::Vector2f(width, height));
    if (!texture.loadFromFile("Perseus.png")) {
        std::cout << "Error: Could not load Perseus.png" << std::endl;
    }

    sprite.setTexture(texture);

}

void Player::setVelocity(const sf::Vector2f& vel) {
    velocity = vel;
}

void Player::updatePosition(float deltaTime) {
    shape.move(velocity * deltaTime);
}

void Player::draw(sf::RenderWindow& window) const {
    window.draw(sprite);
}

sf::FloatRect Player::getBounds() const {
    return shape.getGlobalBounds();
}

// New method to set the position of the player
void Player::setPosition(float x, float y) {
    shape.setPosition(x, y);
}
