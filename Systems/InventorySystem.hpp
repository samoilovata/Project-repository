#pragma once
#include "../IDManager.hpp"
#include "../ECS/System.hpp"

class InventorySystem : public System {
public:
    static void addObjectInInventory(EntityManager& entityManager, std::shared_ptr<Entity> object);
    void removeObjectsFromInventory(EntityManager& entityManager, std::shared_ptr<Entity> object);
    void swapObjectsInInventory(EntityManager& entityManager, int iter);

    void update(EntityManager& entityManager, sf::Time &deltaTime) override;
};
