#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include "../IDManager.hpp"
#include "../ECS/System.hpp"
#include "InventorySystem.hpp"
#include "../EntityManager.hpp"


class RenderSystem : public System {
public:
    void setBackground(std::string fileName, sf::Vector2f position);
    void setDescription(std::string fileName);
    void setPositionObjects(std::shared_ptr<TransformComponent> transformComponent, int n);
    void render(EntityManager& entityManager, sf::RenderWindow& window);
    void update(EntityManager& entityManager, sf::Time& deltaTime) override;

private:
    sf::Texture descriptionTexture;
    sf::Sprite descriptionSprite;
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
};
