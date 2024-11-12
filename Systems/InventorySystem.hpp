#pragma once
#include "../IDManager.hpp"
#include "../ECS/System.hpp"

class InventorySystem : public System {
public:
    void addObjectInInventory(std::vector<std::shared_ptr<Entity>> &objects, std::shared_ptr<Entity> object);
    void removeObjectsFromInventory(std::vector<std::shared_ptr<Entity>> &objects, std::shared_ptr<Entity> object);
    void swapObjectsInInventory(std::vector<std::shared_ptr<Entity>> &objects, std::shared_ptr<Entity> object);

    void update(std::vector<std::shared_ptr<Entity>> &objects, std::vector<std::shared_ptr<Entity>>& entities, sf::Time &deltaTime) override;
};
