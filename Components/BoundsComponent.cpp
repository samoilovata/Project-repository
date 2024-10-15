#include "BoundsComponent.hpp"

void BoundsComponent::setBounds(sf::Sprite &sprite) {
    bounds = sprite.getGlobalBounds();
}

void BoundsComponent::setBounds(sf::Vector2f &position) {
    bounds.left += position.x;
    bounds.top += position.y;
}

sf::FloatRect BoundsComponent::getBounds() {
    return bounds;
}
