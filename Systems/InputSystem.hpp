#pragma once
#include <SFML/Graphics.hpp>
#include "../ECS/System.hpp"

class InputSystem : public System {
public:
    void update(sf::Time& deltaTime) override;

private:
    int frame = 1;
    float currentFrame = 0;
};