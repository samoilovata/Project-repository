#pragma once
#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>
#include "Entity.hpp"

class System {
public:
    virtual ~System() = default;
    virtual void update(float time, std::vector<std::shared_ptr<Entity>>& entities, sf::Time& deltaTime) = 0;
};
