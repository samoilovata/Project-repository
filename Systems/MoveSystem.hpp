#pragma once
#include <SFML/Graphics.hpp>
#include "../ECS/System.hpp"

class MoveSystem : public System
{
public:
    void update(sf::Time& deltaTime) override;
};