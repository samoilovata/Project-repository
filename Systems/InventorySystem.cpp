#include <algorithm>
#include "InventorySystem.hpp"
#include "../Entities/ObjectEntity.hpp"

void InventorySystem::addObjectInInventory(EntityManager entityManager, std::shared_ptr<Entity> object) {
    entityManager.objects.push_back(object);
}

void InventorySystem::removeObjectsFromInventory(EntityManager entityManager,  std::shared_ptr<Entity> object) {
    entityManager.objects.erase(entityManager.objects.begin());
}

void InventorySystem::swapObjectsInInventory(EntityManager entityManager, std::shared_ptr<Entity> object) {
    std::swap(*entityManager.objects.begin(), *std::find(entityManager.objects.begin(), entityManager.objects.end(),object));
}

void InventorySystem::update(EntityManager entityManager, sf::Time& deltaTime) {
    for (auto &entity : entityManager.entities) {
        if (entity->flag == OBJECT && IDManager::getInInventory(entity->ID) &&
        std::find(entityManager.objects.begin(), entityManager.objects.end(), entity) == entityManager.objects.end()) {
            addObjectInInventory(entityManager, entity);
        }
    }
}
