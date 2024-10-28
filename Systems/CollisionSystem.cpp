#include <iostream>
#include "CollisionSystem.hpp"
#include "../Components/BoundsComponent.hpp"
#include "../Components/TransformComponent.hpp"
#include "../Components/InputComponent.hpp"

void CollisionSystem::update(sf::Time &deltaTime) {
    for (size_t i = 0; i < vectorEntity.size() - 1; i++) {
        auto entity1 = vectorEntity[i];
        auto entity1TransformComponent = entity1->getComponent<TransformComponent>();
        auto entity1BoundsComponent = entity1->getComponent<BoundsComponent>();
        auto entity1Position = entity1TransformComponent->getPosition();

        if (entity1TransformComponent && entity1BoundsComponent) {
            entity1BoundsComponent->setBounds(entity1Position);

            for (size_t j = i + 1; j < vectorEntity.size(); j++) {
                auto entity2 = vectorEntity[j];
                auto entity2TransformComponent = entity2->getComponent<TransformComponent>();
                auto entity2BoundsComponent = entity2->getComponent<BoundsComponent>();
                auto entity2Position = entity2TransformComponent->getPosition();

                if (entity2TransformComponent && entity2BoundsComponent) {
                    entity2BoundsComponent->setBounds(entity2Position);

                    if (entity1BoundsComponent->getBounds().intersects(entity2BoundsComponent->getBounds())) {
                        handleCollision(entity1, entity2);
                    }
                }
            }
        }
    }
}

void CollisionSystem::handleCollision(std::shared_ptr<Entity> entity1, std::shared_ptr<Entity> entity2) {
    auto entity1InputComponent = entity1->getComponent<InputComponent>();
    if (entity1InputComponent) {
        if (entity1InputComponent->keyPressed(sf::Keyboard::F) && entity2->getValue()) {
            inventory->addObjectInInventory(entity2);
            entity2->changeValue();
        }
    }
}
