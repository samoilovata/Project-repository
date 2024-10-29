#pragma once
#include <memory>
#include "../ECS/Entity.hpp"
#include "../Components/BoundsComponent.hpp"
#include "../Components/SpriteComponent.hpp"
#include "../Components/TransformComponent.hpp"

class ObjectEntity : public Entity {
public:
    void spawnObjectEntity(const std::string& spritePath, float posX, float posY,
                           int spriteX, int spriteY, int spriteWidth, int spriteHeight);

    void changeInInventory();
    bool getInInventory();

private:
    std::shared_ptr<BoundsComponent> bounds;
    std::shared_ptr<SpriteComponent> sprite;
    std::shared_ptr<TransformComponent> transform;

    bool inInventory = false;
};
