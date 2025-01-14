#pragma once
#include "../ECS/Entity.hpp"
#include "../Components/BoundsComponent.hpp"
#include "../Components/SpriteComponent.hpp"
#include "../Components/TransformComponent.hpp"
#include "../Components/CollisionComponent.hpp"

class StaticObjectEntity : public Entity {
public:
    std::shared_ptr<BoundsComponent> bounds;
    std::shared_ptr<SpriteComponent> sprite;
    std::shared_ptr<TransformComponent> transform;
    std::shared_ptr<CollisionComponent> collision;
};
