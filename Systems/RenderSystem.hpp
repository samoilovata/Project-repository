#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include "../IDManager.hpp"
#include "../ECS/System.hpp"
#include "InventorySystem.hpp"

class RenderSystem : public System {
public:
    void setBackground(std::string fileName, sf::Vector2f position);
    void render(std::vector<std::shared_ptr<Entity>> &objects, std::vector<std::shared_ptr<Entity>> &entities, sf::RenderWindow &window);
    void update(std::vector<std::shared_ptr<Entity>> &objects, std::vector<std::shared_ptr<Entity>> &entities, sf::Time& deltaTime) override;

private:
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
};
