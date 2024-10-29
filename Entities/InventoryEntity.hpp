#pragma once
#include <memory>
#include <vector>
#include "ObjectEntity.hpp"
#include "../ECS/Entity.hpp"
#include "../Components/BoundsComponent.hpp"
#include "../Components/InputComponent.hpp"
#include "../Components/SpriteComponent.hpp"
#include "../Components/TransformComponent.hpp"

class InventoryEntity : public Entity {
public:
    void spawnInventoryEntity(const std::string& spritePath, float posX, float posY,
                              int spriteX, int spriteY, int spriteWidth, int spriteHeight);
private:
    std::shared_ptr<BoundsComponent> bounds;
    std::shared_ptr<InputComponent> input;
    std::shared_ptr<SpriteComponent> sprite;
    std::shared_ptr<TransformComponent> transform;
};
