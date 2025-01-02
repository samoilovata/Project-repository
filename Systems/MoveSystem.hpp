#pragma once
#include "../ECS/System.hpp"

class MoveSystem : public System {
public:
    void update(EntityManager& entityManager, sf::Time& deltaTime) override;

private:
    int frame = 1;
    float currentFrame = 0;

    bool up = false, down = false, left = false, right = false;
};
