#pragma once
#include "../ECS/System.hpp"

class InteractionSystem : public System {
public:
    void update(EntityManager& entityManager, sf::Time& deltaTime) override;
};
