#include "Entity.hpp"
#include "../Components/BoundsComponent.hpp"
#include "../Components/InputComponent.hpp"
#include "../Components/SpriteComponent.hpp"
#include "../Components/TransformComponent.hpp"
#include "../Components/CollisionComponent.hpp"

void Entity::addComponent(std::shared_ptr<Component> ptrComponent) {
    vectorComponent.push_back(ptrComponent);
}

template<typename T>
std::shared_ptr<T> Entity::getComponent() {
    for (auto& component : vectorComponent) {
        if (std::shared_ptr<T> comp = std::dynamic_pointer_cast<T>(component)) return comp;
    }
    return nullptr;
}

template std::shared_ptr<BoundsComponent> Entity::getComponent<BoundsComponent>();
template std::shared_ptr<InputComponent> Entity::getComponent<InputComponent>();
template std::shared_ptr<SpriteComponent> Entity::getComponent<SpriteComponent>();
template std::shared_ptr<TransformComponent> Entity::getComponent<TransformComponent>();
template std::shared_ptr<CollisionComponent> Entity::getComponent<CollisionComponent>();
