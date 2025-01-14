#pragma once
#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>
#include "Entity.hpp"
#include "../EntityManager.hpp"

class System {
public:
    virtual ~System() = default;
    virtual void update(EntityManager& entityManager, sf::Time& deltaTime) = 0;
};
