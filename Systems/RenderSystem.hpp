#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include "../IDManager.hpp"
#include "../ECS/System.hpp"
#include "InventorySystem.hpp"
#include "../EntityManager.hpp"


class RenderSystem : public System {
public:
    void setPositionObjects(std::shared_ptr<TransformComponent> transformComponent, int n);
    void render(EntityManager& entityManager, sf::RenderWindow& window);
    void update(EntityManager& entityManager, sf::Time& deltaTime) override;
};
