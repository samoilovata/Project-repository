#include "SpriteComponent.h"

SpriteComponent::SpriteComponent(const std::string& texturePath) {
    if (!texture.loadFromFile(texturePath)) {
        std::cerr << "Failed to load texture image!" << std::endl;
    }
    sprite.setTexture(texture);
}

void SpriteComponent::setPosition(float x, float y) {
    sprite.setPosition(x, y);
}

sf::Sprite& SpriteComponent::getSprite() {
    return sprite;
}
