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
                sprite->setTexture(1189, 510, 1021, 1021);
                sprite->setScale(6000 * 1.25, 6000);
            } else if (objectEntity->flag == INTERACTIVE_OBJECT && objectEntity->getComponent<CollisionComponent>()->getCollision() && !entityManager.inventory.empty()) {
                if (IDManager::getIsCoin(entityManager.inventory[0]->ID) == IDManager::getIsCoin(objectEntity->ID)) {
                    IDManager::changeInInventory(entityManager.inventory[0]->ID);
                }
            }
        }
    }
}
