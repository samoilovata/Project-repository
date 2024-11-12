#include <iostream>
#include "CollisionSystem.hpp"
#include "InventorySystem.hpp"
#include "../Components/BoundsComponent.hpp"
#include "../Components/TransformComponent.hpp"
#include "../Components/InputComponent.hpp"
#include "../Entities/PlayerEntity.hpp"

void CollisionSystem::update(std::vector<std::shared_ptr<Entity>>& entities, sf::Time &deltaTime) {
    for (size_t i = 0; i < entities.size() - 1; i++) {
        auto entity1 = entities[i];
        auto entity1TransformComponent = entity1->getComponent<TransformComponent>();
        auto entity1BoundsComponent = entity1->getComponent<BoundsComponent>();
        auto entity1CollisionComponent = entity1->getComponent<CollisionComponent>();
        auto entity1Position = entity1TransformComponent->getPosition();

        if (entity1TransformComponent && entity1BoundsComponent) {
            entity1BoundsComponent->setBounds(entity1Position);

            for (size_t j = i + 1; j < entities.size(); j++) {
                auto entity2 = entities[j];
                auto entity2TransformComponent = entity2->getComponent<TransformComponent>();
                auto entity2BoundsComponent = entity2->getComponent<BoundsComponent>();
                auto entity2CollisionComponent = entity2->getComponent<CollisionComponent>();
                auto entity2Position = entity2TransformComponent->getPosition();

                if (entity2TransformComponent && entity2BoundsComponent) {
                    entity2BoundsComponent->setBounds(entity2Position);

                    if (entity1CollisionComponent && entity2CollisionComponent) {
                        if (entity1BoundsComponent->getBounds().intersects(entity2BoundsComponent->getBounds())) {
                            entity1CollisionComponent->collisionTrue();
                            entity2CollisionComponent->collisionTrue();
                        } else {
                            entity1CollisionComponent->collisionFalse();
                            entity2CollisionComponent->collisionFalse();
                        }
                    }
                }
            }
        }
    }
}



void CollisionSystem::handleCollision(std::shared_ptr<Entity> entity1, std::shared_ptr<Entity> entity2) {
    std::shared_ptr<PlayerEntity> en1 = std::dynamic_pointer_cast<PlayerEntity>(entity1);
    std::shared_ptr<PlayerEntity> en2 = std::dynamic_pointer_cast<PlayerEntity>(entity2);
    std::shared_ptr<ObjectEntity> en3;

    if (en1 != nullptr) {
        en3 = std::dynamic_pointer_cast<ObjectEntity>(entity2);

        if (entity1->getComponent<InputComponent>()->keyPressed(sf::Keyboard::F) && IDManager::getIsRender(entity2->ID)) {
            if (en3 != nullptr) {
                IDManager::changeIsRender(en3->ID);
                IDManager::changeInInventory(en3->ID);
                en3->getComponent<TransformComponent>()->setPosition(265, 220);
            }
        }
    } else if (en2 != nullptr) {
        en3 = std::dynamic_pointer_cast<ObjectEntity>(entity1);

        if (entity2->getComponent<InputComponent>()->keyPressed(sf::Keyboard::F) && IDManager::getIsRender(entity1->ID)) {
            if (en3 != nullptr) {
                IDManager::changeIsRender(en3->ID);
                IDManager::changeInInventory(en3->ID);
                en3->getComponent<TransformComponent>()->setPosition(265, 220);
            }
        }
    }
}
