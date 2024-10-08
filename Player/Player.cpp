#include "Player.hpp"
#include <iostream>
#include <filesystem>

void Player::setSprite() {

    if (!playerTexture.loadFromFile(std::filesystem::current_path().string() + "/../Assets/spritePlayer.png")) {
        std::cerr << "Failed to load background image!" << std::endl;
    }

    playerSprite.setTexture(playerTexture);
    playerSprite.setTextureRect(sf::IntRect( 0, 0, 190, 310));
    playerSprite.setPosition(200, 200);
}

sf::Sprite Player::getSprite() {
    return playerSprite;
}