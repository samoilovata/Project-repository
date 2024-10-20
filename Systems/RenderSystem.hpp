#pragma once
#include <SFML/Graphics.hpp>
#include "../ECS/System.hpp"

class RenderSystem : public System {
public:
    void render(sf::RenderWindow& window);
    void update(sf::Time& deltaTime) override;
};