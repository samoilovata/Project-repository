#include "SpriteComponent.hpp"

SpriteComponent::SpriteComponent(const std::string& texturePath, int left, int top, int width, int height) {
    if (!texture.loadFromFile(texturePath)) {
        std::cerr << "Failed to load texture image!" << std::endl;
    }
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(left, top, width, height));
}

void SpriteComponent::setPosition(float x, float y) {
    sprite.setPosition(x, y);
}

void SpriteComponent::setScale(float x, float y) {
    sprite.setScale(800 / x, 640 / y);
}

sf::Sprite& SpriteComponent::getSprite() {
    return sprite;
}
