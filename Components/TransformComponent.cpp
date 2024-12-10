#include "TransformComponent.hpp"

TransformComponent::TransformComponent(float x, float y) : position(x, y) {}

void TransformComponent::setPosition(float x, float y) {
    position.x = x;
    position.y = y;
}

void TransformComponent::setPosition(const sf::Vector2f& pos) {
    position = pos;
}

void TransformComponent::translate(float x, float y) {
    position.x += x;
    position.y += y;
}

void TransformComponent::translate(const sf::Vector2f& offset) {
    position += offset;
}

sf::Vector2f TransformComponent::getPosition() const {
    return position;
}
