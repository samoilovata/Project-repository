#include "InventorySystem.hpp"

void InventorySystem::addObjectInInventory(std::shared_ptr<Entity> object) {
    inventory.push_back(object);
}

void InventorySystem::removeObjectsFromInventory(std::shared_ptr<Entity> object) {
    inventory.erase(inventory.begin());
}

void InventorySystem::swapObjectsInInventory(std::shared_ptr<Entity> object) {
    std::swap(*inventory.begin(), *std::find(inventory.begin(), inventory.end(),object));
}
