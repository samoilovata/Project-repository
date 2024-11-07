#pragma once
#include "../ECS/System.hpp"

class InventorySystem : public System {
public:
    void addObjectInInventory(std::shared_ptr<Entity> object);
    void removeObjectsFromInventory(std::shared_ptr<Entity> object);
    void swapObjectsInInventory(std::shared_ptr<Entity> object);

    void update(float time, std::vector<std::shared_ptr<Entity>>& entities, sf::Time &deltaTime) override;

private:
    std::vector<std::shared_ptr<Entity>> inventory;
};
