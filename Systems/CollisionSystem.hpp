#pragma once
#include <memory>
#include <SFML/System.hpp>
#include "../IDManager.hpp"
#include "../Entities/InventoryEntity.hpp"
#include "../ECS/System.hpp"

class CollisionSystem : public System {
public:
    void update(std::vector<std::shared_ptr<Entity>>& entities, sf::Time &deltaTime) override;

private:
    void handleCollision(std::shared_ptr<Entity> entity1, std::shared_ptr<Entity> entity2);
};
