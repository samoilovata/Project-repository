#include "CollisionComponent.hpp"

void CollisionComponent::collisionTrue() {
    collision = true;
}

void CollisionComponent::collisionFalse() {
    collision = false;
}

bool CollisionComponent::getCollision() {
    return collision;
}
