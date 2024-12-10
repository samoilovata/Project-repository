#pragma once
#include <SFML/Graphics.hpp>
#include "../IDManager.hpp"
#include "../ECS/System.hpp"

class InputSystem : public System {
public:
    void update(EntityManager& entityManager, sf::Time& deltaTime) override;

private:
    int frame = 1;
    float currentFrame = 0;
};