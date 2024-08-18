#ifndef FLOOR_H
#define FLOOR_H

#include <SFML/Graphics.hpp>

class Floor {
private:
    sf::RectangleShape shape;  // SFML shape representing the floor

public:
    // Constructor to initialize the floor with position and size
    Floor(float x, float y, float width, float height);

    // Method to get the bounding box of the floor for collision detection
    sf::FloatRect getBounds() const;

    // Method to draw the floor on the window
    void draw(sf::RenderWindow& window) const;

    // Method to set the texture of the floor
    void setTexture(const sf::Texture& texture);

    // Method to set the color of the floor
    void setColor(const sf::Color& color);
};

#endif // FLOOR_H
