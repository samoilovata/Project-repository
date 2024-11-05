#pragma once
#include <memory>
#include "../EntityManager.hpp"
#include "../ECS/Entity.hpp"
#include "../Components/BoundsComponent.hpp"
#include "../Components/InputComponent.hpp"
#include "../Components/SpriteComponent.hpp"
#include "../Components/TransformComponent.hpp"

class PlayerEntity : public Entity {
private:
    std::shared_ptr<BoundsComponent> bounds;
    std::shared_ptr<InputComponent> input;
    std::shared_ptr<SpriteComponent> sprite;
    std::shared_ptr<TransformComponent> transform;

    friend class EntityManager;
};
