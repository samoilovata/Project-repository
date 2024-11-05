#pragma once
#include <SFML/Graphics.hpp>
#include "../ECS/System.hpp"

class InputSystem : public System {
public:
    void update(float time, sf::Time& deltaTime) override;

private:
    float currentFrame = 0;
};