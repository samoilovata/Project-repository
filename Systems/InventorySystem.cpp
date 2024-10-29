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
        std::shared_ptr<ObjectEntity> en1 = std::dynamic_pointer_cast<ObjectEntity>(entity);
        if (en1 != nullptr && en1->getInInventory() && std::find(inventory.begin(), inventory.end(), en1) == inventory.end()) {
            addObjectInInventory(en1);
        }
    }
}
