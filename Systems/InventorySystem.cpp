#include <algorithm>
#include "InventorySystem.hpp"
#include "../Entities/ObjectEntity.hpp"

void InventorySystem::addObjectInInventory(std::shared_ptr<Entity> object) {
    inventory.push_back(object);
}

void InventorySystem::removeObjectsFromInventory(std::shared_ptr<Entity> object) {
    inventory.erase(inventory.begin());
}

void InventorySystem::swapObjectsInInventory(std::shared_ptr<Entity> object) {
    std::swap(*inventory.begin(), *std::find(inventory.begin(), inventory.end(),object));
}

void InventorySystem::update(std::vector<std::shared_ptr<Entity>>& entities, sf::Time& deltaTime) {
    for (auto &entity : entities) {
        if (entity->flag == object && IDManager::getInInventory(entity->ID) &&
        std::find(inventory.begin(), inventory.end(), entity) == inventory.end()) {
            addObjectInInventory(entity);
        }
    }
}
