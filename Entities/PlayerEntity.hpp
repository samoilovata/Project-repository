#pragma once
#include <memory>
#include "../ECS/Entity.hpp"
#include "../Components/BoundsComponent.hpp"
#include "../Components/InputComponent.hpp"
#include "../Components/SpriteComponent.hpp"
#include "../Components/TransformComponent.hpp"
#include "../Components/CollisionComponent.hpp"

class PlayerEntity : public Entity {
public:
    void spawnPlayerEntity(const std::string& spritePath, float posX, float posY,
                 int spriteX, int spriteY, int spriteWidth, int spriteHeight);

private:
    std::shared_ptr<BoundsComponent> bounds;
    std::shared_ptr<InputComponent> input;
    std::shared_ptr<SpriteComponent> sprite;
    std::shared_ptr<TransformComponent> transform;
    std::shared_ptr<CollisionComponent> collision;
};
