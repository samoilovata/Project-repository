#pragma once
#include <memory>
#include <vector>
#include "ObjectEntity.hpp"
#include "../EntityManager.hpp"
#include "../ECS/Entity.hpp"
#include "../Components/BoundsComponent.hpp"
#include "../Components/InputComponent.hpp"
#include "../Components/SpriteComponent.hpp"
#include "../Components/TransformComponent.hpp"

class InventoryEntity : public Entity {
private:
    std::shared_ptr<InputComponent> input;
    std::shared_ptr<SpriteComponent> sprite;
    std::shared_ptr<TransformComponent> transform;

    friend class EntityManager;
};
