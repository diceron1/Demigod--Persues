#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include "AABBCollision.h"

class Player {
private:
    sf::RectangleShape shape;
    sf::Vector2f velocity;
    sf::Texture texture;
    sf::Sprite sprite;

    //Calculate size of sprite bounds
    sf::FloatRect calculateSpriteBounds(const sf::Texture& texture);

    //Animation Variables
    sf::IntRect currentFrame; // The rectangle to select the current frame from the sprite sheet
    float animationTimer;
    float animationSpeed;
    int frameCount;

    float width = 128;
    float height = 128;

public:
    Player(float x, float y);

    void setVelocity(const sf::Vector2f& vel);
    void updatePosition(float deltaTime);
    void updateAnimation(float deltaTime);
    void draw(sf::RenderWindow& window) const;

    sf::FloatRect getBounds() const;

    // New method to set the position of the player
    void setPosition(float x, float y);




};

#endif // PLAYER_H
