#include <algorithm>
#include "InventorySystem.hpp"
#include "../Entities/ObjectEntity.hpp"

void InventorySystem::addObjectInInventory(EntityManager& entityManager, std::shared_ptr<Entity> object) {
    entityManager.inventory.push_back(object);
}

void InventorySystem::removeObjectsFromInventory(EntityManager& entityManager,  std::shared_ptr<Entity> object) {
    entityManager.inventory.erase(entityManager.inventory.begin());
}

void InventorySystem::swapObjectsInInventory(EntityManager& entityManager, std::shared_ptr<Entity> object) {
    std::swap(*entityManager.inventory.begin(), *std::find(entityManager.inventory.begin(), entityManager.inventory.end(), object));
}

void InventorySystem::update(EntityManager& entityManager, sf::Time& deltaTime) {
    for (auto &entity : entityManager.entities) {
        if (entity->flag == OBJECT && IDManager::getInInventory(entity->ID) &&
            std::find(entityManager.inventory.begin(), entityManager.inventory.end(), entity) == entityManager.inventory.end()) {

            addObjectInInventory(entityManager, entity);
            entityManager.updateActiveSlot();
        }
    }
}
