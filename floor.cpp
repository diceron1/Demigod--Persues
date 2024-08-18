#include "Floor.h"

// Constructor definition
Floor::Floor(float x, float y, float width, float height) {
    shape.setPosition(x, y);
    shape.setSize(sf::Vector2f(width, height));
    shape.setFillColor(sf::Color::Blue);  // Default color for the floor
}

// Get the bounding box of the floor
sf::FloatRect Floor::getBounds() const {
    return shape.getGlobalBounds();
}

// Method to draw the floor on the window
void Floor::draw(sf::RenderWindow& window) const {
    window.draw(shape);
}

// Method to set the texture of the floor
void Floor::setTexture(const sf::Texture& texture) {
    shape.setTexture(&texture);
}

// Method to set the color of the floor
void Floor::setColor(const sf::Color& color) {
    shape.setFillColor(color);
}
