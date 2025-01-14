#include "InteractionSystem.hpp"
#include "../IDManager.hpp"

void InteractionSystem::update(EntityManager& entityManager, sf::Time& deltaTime) {
    if (EntityManager::keyStatus[sf::Keyboard::F]) {
        for (auto &objectEntity : entityManager.entities) {
            if (objectEntity->flag == OBJECT && objectEntity->getComponent<CollisionComponent>()->getCollision() && IDManager::getIsRender(objectEntity->ID)) {
                IDManager::changeIsRender(objectEntity->ID);
                IDManager::changeInInventory(objectEntity->ID);

                auto sprite = objectEntity->getComponent<SpriteComponent>();
                objectEntity->getComponent<TransformComponent>()->setPosition(60, 395);
                sprite->setTexture(0, 0, 127, 127);
                sprite->sprite.setScale(1, 1);
                break;
            } else if (objectEntity->flag == INTERACTIVE_OBJECT && objectEntity->getComponent<CollisionComponent>()->getCollision() && entityManager.inventory.empty()) {
                if (IDManager::getIsCoin(objectEntity->ID)) {
                    entityManager.scriptStatus = entityManager.scriptStatus | (1 << 1);
                    objectEntity->getComponent<DescriptionComponent>()->setText("");
                    IDManager::changeIsCoin(objectEntity->ID);
                    break;
                }
            } else if (objectEntity->flag == INTERACTIVE_OBJECT && objectEntity->getComponent<CollisionComponent>()->getCollision() && !entityManager.inventory.empty()) {
                if (IDManager::getIsCoin(entityManager.inventory[0]->ID) == IDManager::getIsCoin(objectEntity->ID) &&
                    IDManager::getIsCoin(objectEntity->ID)) {
                    IDManager::changeInInventory(entityManager.inventory[0]->ID);
                    entityManager.scriptStatus = entityManager.scriptStatus | 1;
                    objectEntity->getComponent<DescriptionComponent>()->setText("");
                    break;
                }

                if (IDManager::getIsSeeds(entityManager.inventory[0]->ID) == IDManager::getIsSeeds(objectEntity->ID) &&
                    IDManager::getIsSeeds(objectEntity->ID)) {
                    IDManager::changeInInventory(entityManager.inventory[0]->ID);
                    entityManager.scriptStatus = entityManager.scriptStatus | (1 << 2);
                    objectEntity->getComponent<DescriptionComponent>()->setText("");
                    break;
                }

                if (IDManager::getIsBerry1(entityManager.inventory[0]->ID) ==
                    IDManager::getIsBerry1(objectEntity->ID) && IDManager::getIsBerry1(objectEntity->ID) &&
                    IDManager::getIsBerry2(objectEntity->ID)) {
                    IDManager::changeInInventory(entityManager.inventory[0]->ID);
                    IDManager::changeIsBerry1(objectEntity->ID);
                    endingCounter++;

                    objectEntity->getComponent<SpriteComponent>()->getSprite().setTextureRect(
                            sf::IntRect(22, 1, 21, 28));
                } else if (IDManager::getIsBerry2(entityManager.inventory[0]->ID) ==
                           IDManager::getIsBerry2(objectEntity->ID) && IDManager::getIsBerry1(objectEntity->ID) &&
                           IDManager::getIsBerry2(objectEntity->ID)) {
                    IDManager::changeInInventory(entityManager.inventory[0]->ID);
                    IDManager::changeIsBerry2(objectEntity->ID);
                    endingCounter++;

                    objectEntity->getComponent<SpriteComponent>()->getSprite().setTextureRect(
                            sf::IntRect(22, 1, 21, 28));
                } else if (IDManager::getIsFlower1(entityManager.inventory[0]->ID) ==
                           IDManager::getIsFlower1(objectEntity->ID) && IDManager::getIsFlower1(objectEntity->ID) &&
                           IDManager::getIsFlower2(objectEntity->ID)) {
                    IDManager::changeInInventory(entityManager.inventory[0]->ID);
                    IDManager::changeIsFlower1(objectEntity->ID);
                    endingCounter++;

                    objectEntity->getComponent<SpriteComponent>()->getSprite().setTextureRect(
                            sf::IntRect(22, 1, 21, 28));
                } else if (IDManager::getIsFlower2(entityManager.inventory[0]->ID) ==
                           IDManager::getIsFlower2(objectEntity->ID) && IDManager::getIsFlower1(objectEntity->ID) &&
                           IDManager::getIsFlower2(objectEntity->ID)) {
                    IDManager::changeInInventory(entityManager.inventory[0]->ID);
                    IDManager::changeIsFlower2(objectEntity->ID);
                    endingCounter++;

                    objectEntity->getComponent<SpriteComponent>()->getSprite().setTextureRect(
                            sf::IntRect(22, 1, 21, 28));
                } else if (IDManager::getIsFish1(entityManager.inventory[0]->ID) ==
                           IDManager::getIsFish1(objectEntity->ID) && IDManager::getIsFish1(objectEntity->ID) &&
                           IDManager::getIsFish2(objectEntity->ID)) {
                    IDManager::changeInInventory(entityManager.inventory[0]->ID);
                    IDManager::changeIsFish1(objectEntity->ID);
                    endingCounter++;

                    objectEntity->getComponent<SpriteComponent>()->getSprite().setTextureRect(
                            sf::IntRect(22, 1, 21, 28));
                } else if (IDManager::getIsFish2(entityManager.inventory[0]->ID) ==
                           IDManager::getIsFish2(objectEntity->ID) && IDManager::getIsFish1(objectEntity->ID) &&
                           IDManager::getIsFish2(objectEntity->ID)) {
                    IDManager::changeInInventory(entityManager.inventory[0]->ID);
                    IDManager::changeIsFish2(objectEntity->ID);
                    endingCounter++;

                    objectEntity->getComponent<SpriteComponent>()->getSprite().setTextureRect(
                            sf::IntRect(22, 1, 21, 28));
                }

                if (endingCounter == 3) entityManager.scriptStatus = entityManager.scriptStatus | (1 << 3);

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
