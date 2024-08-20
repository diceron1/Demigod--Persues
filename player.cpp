#include "Player.h"
#include "iostream"

Player::Player(float x, float y) {

    if (!texture.loadFromFile("D:/C++/Demigod--Persues/PerseusSprite.png")) {
        std::cout << "Error: Could not load Perseus.png" << std::endl;
    }

    sprite.setTexture(texture);

    //Initialize Animation
    frameCount = 2;
    animationSpeed = 0.15f;
    animationTimer = 0.0f;

    currentFrame = sf::IntRect(0, 0, 128, 128);

    shape.setSize(sf::Vector2f(currentFrame.width, currentFrame.height));
    shape.setPosition(x, y);

    sprite.setTextureRect(currentFrame);
    sprite.setPosition(x, y);


    //Calculate the sprite's bounding box based on the non-transparent pixels
    sf::FloatRect bounds = calculateSpriteBounds(texture);

    //Adjust the sprite's position to match the shape
    //sprite.setPosition(shape.getPosition());


}

void Player::setVelocity(const sf::Vector2f& vel) {
    velocity = vel;
}

void Player::updatePosition(float deltaTime) {
    shape.move(velocity * deltaTime);
    sprite.setPosition(shape.getPosition());  // Sync sprite with the shape

    updateAnimation(deltaTime);
}

void Player::updateAnimation(float deltaTime) {
    animationTimer += deltaTime;

    if (animationTimer >= animationSpeed) {
        animationTimer = 0.0f;

        // Move to the next frame
        currentFrame.left += currentFrame.width;
        if (currentFrame.left >= texture.getSize().x) {
            currentFrame.left = 0;  // Loop back to the first frame
        }

        sprite.setTextureRect(currentFrame);  // Update the sprite to show the correct frame
    }

    // Ensure the sprite's position matches the shape position
    sprite.setPosition(shape.getPosition());
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

sf::FloatRect Player::calculateSpriteBounds(const sf::Texture& texture) {
    const sf::Image& image = texture.copyToImage();
    sf::Vector2u size = image.getSize();

    int left = size.x, top = size.y, right = 0, bottom = 0;

    for (unsigned int y = 0; y < size.y; y++) {
        for (unsigned int x = 0; x < size.x; x++) {
            if (image.getPixel(x, y).a != 0) {  // Non-transparent pixel
                if (x < left) left = x;
                if (x > right) right = x;
                if (y < top) top = y;
                if (y > bottom) bottom = y;
            }
        }
    }

    // Return the bounding box as a FloatRect
    return sf::FloatRect(left, top, right - left, bottom - top);
}
