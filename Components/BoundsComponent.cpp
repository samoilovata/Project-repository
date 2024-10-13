#include "BoundsComponent.hpp"

void BoundsComponent::setBounds(sf::Sprite &sprite) {
    bounds = sprite.getGlobalBounds();
}

sf::FloatRect BoundsComponent::getBounds() {
    return bounds;
}
