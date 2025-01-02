#pragma once
#include "../ECS/System.hpp"

class MoveSystem : public System {
public:
    std::pair<int, int> move = {0, -1};
    void update(EntityManager& entityManager, sf::Time& deltaTime) override;
private:
    int frame = 1;
    float currentFrame = 0;
};
