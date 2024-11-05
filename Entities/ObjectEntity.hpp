#pragma once
#include <memory>
#include "../EntityManager.hpp"
#include "../ECS/Entity.hpp"
#include "../Components/BoundsComponent.hpp"
#include "../Components/SpriteComponent.hpp"
#include "../Components/TransformComponent.hpp"

class ObjectEntity : public Entity {
public:
    void changeInInventory();
    bool getInInventory();

private:
    std::shared_ptr<BoundsComponent> bounds;
    std::shared_ptr<SpriteComponent> sprite;
    std::shared_ptr<TransformComponent> transform;

    bool inInventory = false;

    friend class EntityManager;
};
