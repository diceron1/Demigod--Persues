#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Floor.h"

int main()
{
    // Get the current desktop resolution
    sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();

    // Create the window in fullscreen mode
    sf::RenderWindow window(desktopMode, "Demigod: Perseus", sf::Style::Fullscreen);

    // Calculate scale factors for different resolutions
    float scaleX = static_cast<float>(desktopMode.width) / 1080.f;
    float scaleY = static_cast<float>(desktopMode.height) / 720.f;

    // Adjust player size and position based on scale factors
    Player player(540 * scaleX, 360 * scaleY);

    // Create floor segments for the level, adjusted for resolution scaling
    Floor floor1(0, 670 * scaleY, desktopMode.width, 50 * scaleY);  // Ground floor
    Floor platform1(300 * scaleX, 500 * scaleY, 200 * scaleX, 20 * scaleY);  // Floating platform
    Floor platform2(600 * scaleX, 400 * scaleY, 200 * scaleX, 20 * scaleY);  // Another platform

    sf::Clock clock;
    sf::Vector2f velocity(0.f, 0.f);  // Initialize the velocity vector
    bool is_jumping = false;
    bool on_ground = false;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();  // Allow exiting fullscreen with Escape
            }
        }

        // Continuous input handling
        velocity.x = 0.f;  // Reset horizontal velocity to 0 before checking inputs

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            velocity.x = -200.f * scaleX;  // Move left
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            velocity.x = 200.f * scaleX;  // Move right
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && on_ground) {
            is_jumping = true;
            on_ground = false;
            velocity.y = -300.f * scaleY;  // Jump
        }

        float deltaTime = clock.restart().asSeconds();

        // Apply gravity if the player is not on the ground
        if (!on_ground) {
            velocity.y += 9.8f * 50 * scaleY * deltaTime;
        }

        // Update player position
        player.setVelocity(velocity);
        player.updatePosition(deltaTime);

        // Boundary checks: Ensure the player stays within the window bounds
        sf::FloatRect playerBounds = player.getBounds();
        if (playerBounds.left < 0) {
            player.setPosition(0, playerBounds.top);
            velocity.x = 0.f;
        }
        if (playerBounds.left + playerBounds.width > window.getSize().x) {
            player.setPosition(window.getSize().x - playerBounds.width, playerBounds.top);
            velocity.x = 0.f;
        }

        // Reset on_ground flag before checking for collisions
        on_ground = false;

        // Check collision with the floor
        sf::FloatRect floorBounds = floor1.getBounds();
        if (playerBounds.intersects(floorBounds)) {
            if (velocity.y > 0) { // Player is falling
                player.setPosition(playerBounds.left, floorBounds.top - playerBounds.height);
                velocity.y = 0.f;
                on_ground = true;
                is_jumping = false;
            }
        }

        // Check collision with platform1
        sf::FloatRect platform1Bounds = platform1.getBounds();
        if (playerBounds.intersects(platform1Bounds)) {
            if (velocity.y > 0 && playerBounds.top < platform1Bounds.top) { // Player is falling
                player.setPosition(playerBounds.left, platform1Bounds.top - playerBounds.height);
                velocity.y = 0.f;
                on_ground = true;
                is_jumping = false;
            }
            else if (velocity.y < 0 && playerBounds.top > platform1Bounds.top) { // Player is jumping upwards
                player.setPosition(playerBounds.left, platform1Bounds.top + platform1Bounds.height);
                velocity.y = 0.f;
            }
        }

        // Check collision with platform2
        sf::FloatRect platform2Bounds = platform2.getBounds();
        if (playerBounds.intersects(platform2Bounds)) {
            if (velocity.y > 0 && playerBounds.top < platform2Bounds.top) { // Player is falling
                player.setPosition(playerBounds.left, platform2Bounds.top - playerBounds.height);
                velocity.y = 0.f;
                on_ground = true;
                is_jumping = false;
            }
            else if (velocity.y < 0 && playerBounds.top > platform2Bounds.top) { // Player is jumping upwards
                player.setPosition(playerBounds.left, platform2Bounds.top + platform2Bounds.height);
                velocity.y = 0.f;
            }
        }

        window.clear();

        // Draw the floor and platforms
        floor1.draw(window);
        platform1.draw(window);
        platform2.draw(window);

        // Draw the player
        player.draw(window);

        window.display();
    }

    return 0;
}
