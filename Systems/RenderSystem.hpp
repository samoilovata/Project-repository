#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include "../ECS/System.hpp"

class RenderSystem : public System {
public:
    void setBackground(std::string fileName, sf::Vector2f position);
    void render(sf::RenderWindow& window);
    void update(sf::Time& deltaTime) override;

private:
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
};
