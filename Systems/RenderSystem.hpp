#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include "../IDManager.hpp"
#include "../ECS/System.hpp"
#include "../EntityManager.hpp"

class RenderSystem : public System {
public:
    void setBackground(std::string fileName, sf::Vector2f position);
    void setDescription(std::string fileName);
    void render(std::vector<std::shared_ptr<Entity>>& entities, sf::RenderWindow& window);
    void update(std::vector<std::shared_ptr<Entity>>& entities, sf::Time& deltaTime) override;

private:
    sf::Texture descriptionTexture;
    sf::Sprite descriptionSprite;
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
};
