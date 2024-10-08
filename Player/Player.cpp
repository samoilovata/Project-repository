#include "Player.hpp"
#include <iostream>
#include <filesystem>

void Player::setSprite() {

    if (!playerTexture.loadFromFile(std::filesystem::current_path().string() + "/../Assets/spritePlayer.png")) {
        std::cerr << "Failed to load background image!" << std::endl;
    }

    playerSprite.setTexture(playerTexture);
    playerSprite.setTextureRect(sf::IntRect( 200, 0, 190, 310));
    playerSprite.setPosition(200, 200);
}

sf::Sprite Player::getSprite() {
    return playerSprite;
}

void Player::movePlayer(float time, sf::Time deltaTime) {
    float currentFrame = 0;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        currentFrame = (int) (3 * time) % 3;
        playerSprite.setTextureRect(sf::IntRect (int(currentFrame) * 200, 980, 200, 320));
        playerSprite.move(-0.0005 * deltaTime.asMicroseconds(), 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        currentFrame = (int) (3 * time) % 3;
        playerSprite.setTextureRect(sf::IntRect (int(currentFrame) * 200, 660, 200, 320));
        playerSprite.move(0.0005 * deltaTime.asMicroseconds(), 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        currentFrame = (int) (3 * time) % 3;
        playerSprite.setTextureRect(sf::IntRect (int(currentFrame) * 200, 330, 200, 320));
        playerSprite.move(0, -0.0005 * deltaTime.asMicroseconds());
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        currentFrame = (int) (3 * time) % 3;
        playerSprite.setTextureRect(sf::IntRect (int(currentFrame) * 200, 0, 200, 320));
        playerSprite.move(0, 0.0005 * deltaTime.asMicroseconds());
    }
}
