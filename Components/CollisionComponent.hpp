#pragma once
#include "../ECS/Component.hpp"

class CollisionComponent : public Component {
public:
    void collisionTrue();
    void collisionFalse();
    bool getCollision() const;

private:
    bool collision = false;
};
