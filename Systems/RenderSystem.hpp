#pragma once
#include "../IDManager.hpp"
#include "../ECS/System.hpp"
#include "InventorySystem.hpp"
#include "../EntityManager.hpp"

class RenderSystem : public System {
public:
    void setPositionObjects(const std::shared_ptr<TransformComponent>& transformComponent, int n);
    void render(EntityManager& entityManager, sf::RenderWindow& window);
    void update(EntityManager& entityManager, sf::Time& deltaTime) override;

private:
    std::shared_ptr<sf::Texture> backgroundTextureEnding;
    sf::Sprite backgroundSpriteEnding;
};
