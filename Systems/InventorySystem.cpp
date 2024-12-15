#include <algorithm>
#include "InventorySystem.hpp"
#include "../Entities/ObjectEntity.hpp"

void InventorySystem::addObjectInInventory(EntityManager& entityManager, std::shared_ptr<Entity> object) {
    entityManager.inventory.push_back(object);
}

void InventorySystem::removeObjectsFromInventory(EntityManager& entityManager,  std::shared_ptr<Entity> object) {
    entityManager.inventory.erase(entityManager.inventory.begin());
}

void InventorySystem::swapObjectsInInventory(EntityManager& entityManager, int iter) {
    std::swap(*entityManager.inventory.begin(), entityManager.inventory[iter]);
}

void InventorySystem::update(EntityManager& entityManager, sf::Time& deltaTime) {
    for (auto &entity : entityManager.entities) {
        if (entity->flag == INVENTORY) {
            if (EntityManager::keyStatus[sf::Keyboard::E] && !IDManager::getIsRender(entity->ID)) {
                IDManager::changeIsRender(entity->ID);
                EntityManager::keyStatus[sf::Keyboard::E] = false;
            } else if (EntityManager::keyStatus[sf::Keyboard::E] && IDManager::getIsRender(entity->ID)) {
                IDManager::changeIsRender(entity->ID);
                EntityManager::keyStatus[sf::Keyboard::E] = false;
            }

            if (IDManager::getIsRender(entity->ID)) {
                if (EntityManager::keyStatus[sf::Keyboard::Num1] && entityManager.inventory.size() >= 2) {
                    swapObjectsInInventory(entityManager, 1);
                    EntityManager::keyStatus[sf::Keyboard::Num1] = false;
                }
                else if (EntityManager::keyStatus[sf::Keyboard::Num2] && entityManager.inventory.size() >= 3) {
                    swapObjectsInInventory(entityManager, 2);
                    EntityManager::keyStatus[sf::Keyboard::Num2] = false;
                }
                else if (EntityManager::keyStatus[sf::Keyboard::Num3] && entityManager.inventory.size() >= 4) {
                    swapObjectsInInventory(entityManager, 3);
                    EntityManager::keyStatus[sf::Keyboard::Num3] = false;
                }
                else if (EntityManager::keyStatus[sf::Keyboard::Num4] && entityManager.inventory.size() >= 5) {
                    swapObjectsInInventory(entityManager, 4);
                    EntityManager::keyStatus[sf::Keyboard::Num4] = false;
                }
                else if (EntityManager::keyStatus[sf::Keyboard::Num5] && entityManager.inventory.size() >= 6) {
                    swapObjectsInInventory(entityManager, 5);
                    EntityManager::keyStatus[sf::Keyboard::Num5] = false;
                }
                else if (EntityManager::keyStatus[sf::Keyboard::Num6] && entityManager.inventory.size() >= 7) {
                    swapObjectsInInventory(entityManager, 6);
                    EntityManager::keyStatus[sf::Keyboard::Num6] = false;
                }
                else if (EntityManager::keyStatus[sf::Keyboard::Num7] && entityManager.inventory.size() >= 8) {
                    swapObjectsInInventory(entityManager, 7);
                    EntityManager::keyStatus[sf::Keyboard::Num7] = false;
                }
                else if (EntityManager::keyStatus[sf::Keyboard::Num8] && entityManager.inventory.size() >= 9) {
                    swapObjectsInInventory(entityManager, 8);
                    EntityManager::keyStatus[sf::Keyboard::Num8] = false;
                }
            }
        }
        else if (entity->flag == OBJECT && IDManager::getInInventory(entity->ID) &&
            std::find(entityManager.inventory.begin(), entityManager.inventory.end(), entity) == entityManager.inventory.end()) {

            addObjectInInventory(entityManager, entity);
            entity->deleteComponent();
            entity->getComponent<CollisionComponent>()->collisionFalse();
        }
    }
    if (!entityManager.inventory.empty() && !IDManager::getInInventory(entityManager.inventory[0]->ID)) {
        removeObjectsFromInventory(entityManager, entityManager.inventory[0]);
    }
}
