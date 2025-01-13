#include "InteractionSystem.hpp"
#include "../IDManager.hpp"

void InteractionSystem::update(EntityManager& entityManager, sf::Time& deltaTime) {
    if (EntityManager::keyStatus[sf::Keyboard::F]) {
        for (auto &objectEntity : entityManager.entities) {
            if (objectEntity->flag == OBJECT && objectEntity->getComponent<CollisionComponent>()->getCollision()) {
                IDManager::changeIsRender(objectEntity->ID);
                IDManager::changeInInventory(objectEntity->ID);

                auto sprite = objectEntity->getComponent<SpriteComponent>();
                objectEntity->getComponent<TransformComponent>()->setPosition(60, 395);
                sprite->setTexture(0, 0, 127, 127);
                sprite->sprite.setScale(1, 1);
                break;
            } else if (objectEntity->flag == INTERACTIVE_OBJECT && objectEntity->getComponent<CollisionComponent>()->getCollision() && !entityManager.inventory.empty()) {
                if (IDManager::getIsCoin(entityManager.inventory[0]->ID) == IDManager::getIsCoin(objectEntity->ID)) {
                    IDManager::changeInInventory(entityManager.inventory[0]->ID);
                    break;
                }
            } else if (objectEntity->flag == LOCATION_OBJECT && objectEntity->getComponent<CollisionComponent>()->getCollision()) {
                entityManager.currentLocation = 3 - entityManager.currentLocation;
                objectEntity->getComponent<CollisionComponent>()->collisionFalse();

                entityManager.playerPtr->getComponent<TransformComponent>()->setPosition(EntityManager::locationStatus[entityManager.currentLocation]->playerDefaultPosition);
                break;
            }
        }
        EntityManager::keyStatus[sf::Keyboard::F] = false;
    }
}
