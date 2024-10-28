#pragma once
#include <memory>
#include <SFML/System.hpp>
#include "../Entities/InventoryEntity.hpp"
#include "../ECS/System.hpp"

class CollisionSystem : public System {
public:
    void update(sf::Time &deltaTime) override;

    std::shared_ptr<InventoryEntity> inventory;

private:
    void handleCollision(std::shared_ptr<Entity> entity1, std::shared_ptr<Entity> entity2);
};
