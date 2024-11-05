#pragma once
#include "../ECS/Component.hpp"

class CollisionComponent : public Component {
public:
    void collisionTrue();
    void collisionFalse();
    bool getCollision();
private:
    bool collision = false;
};
