#pragma once
#include <SFML/Graphics.hpp>
#include "../ECS/System.hpp"

class InputSystem : public System {
public:
    void update(float time, std::vector<std::shared_ptr<Entity>>& entities, sf::Time& deltaTime) override;

private:
    float currentFrame = 0;
};