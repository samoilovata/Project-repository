#include <algorithm>
#include "InventorySystem.hpp"
#include "../Entities/ObjectEntity.hpp"

void InventorySystem::addObjectInInventory(std::vector<std::shared_ptr<Entity>> &objects, std::shared_ptr<Entity> object) {
    objects.push_back(object);
}

void InventorySystem::removeObjectsFromInventory(std::vector<std::shared_ptr<Entity>> &objects, std::shared_ptr<Entity> object) {
    objects.erase(objects.begin());
}

void InventorySystem::swapObjectsInInventory(std::vector<std::shared_ptr<Entity>> &objects, std::shared_ptr<Entity> object) {
    std::swap(*objects.begin(), *std::find(objects.begin(), objects.end(),object));
}

void InventorySystem::update(std::vector<std::shared_ptr<Entity>> &objects, std::vector<std::shared_ptr<Entity>>& entities, sf::Time& deltaTime) {
    for (auto &entity : entities) {
        if (entity->flag == OBJECT && IDManager::getInInventory(entity->ID) &&
        std::find(objects.begin(), objects.end(), entity) == objects.end()) {
            addObjectInInventory(objects, entity);
        }
    }
}
