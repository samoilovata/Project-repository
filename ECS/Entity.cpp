#include "Entity.hpp"

void Entity::addComponent(std::shared_ptr<Component> ptrComponent) {
    vectorComponent.push_back(ptrComponent);
}

std::shared_ptr<Component> Entity::getComponent(std::shared_ptr<Component> ptrComponent) {
    for (auto& component : vectorComponent) {
        if (component == ptrComponent) return component;
    }
    return nullptr;
}
