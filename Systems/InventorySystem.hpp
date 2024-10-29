#pragma once
#include "../ECS/System.hpp"

class InventorySystem : public System {
public:
    void addObjectInInventory(std::shared_ptr<Entity> object);
    void removeObjectsFromInventory(std::shared_ptr<Entity> object);
    void swapObjectsInInventory(std::shared_ptr<Entity> object);
    void update(sf::Time& deltaTime);
private:
    std::vector<std::shared_ptr<Entity>> inventory;
};