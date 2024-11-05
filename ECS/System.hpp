#pragma once
#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>
#include "Entity.hpp"

class System {
public:
    virtual ~System() = default;

    void addEntity(std::shared_ptr<Entity> ptrEntity);
    virtual void update(float time, sf::Time& deltaTime) = 0;

protected:
    std::vector<std::shared_ptr<Entity>> vectorEntity;
};
