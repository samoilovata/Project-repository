#include "tempObject.hpp"
#include <filesystem>
#include <iostream>

void tempObject::setSprite() {

    if (!tempObjectTexture.loadFromFile(std::filesystem::current_path().string() + "/../Assets/coin.png")) {
        std::cerr << "Failed to load background image!" << std::endl;
    }

    tempObjectSprite.setTexture(tempObjectTexture);
    tempObjectSprite.setTextureRect(sf::IntRect(0, 0, 40, 40));
    setPosition(600, 500);
}

void tempObject::setBounds() {
    tempObjectBounds = tempObjectSprite.getGlobalBounds();
}

sf::Sprite tempObject::getSprite() {
    return tempObjectSprite;
}

sf::FloatRect tempObject::getBounds() {
    return tempObjectBounds;
}

void tempObject::setPosition(float x, float y) {
    tempObjectSprite.setPosition(x, y);
    setBounds();
}
