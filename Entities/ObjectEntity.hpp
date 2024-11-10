#pragma once
#include <memory>
#include "../ECS/Entity.hpp"
#include "../Components/BoundsComponent.hpp"
#include "../Components/SpriteComponent.hpp"
#include "../Components/TransformComponent.hpp"
#include "../Components/CollisionComponent.hpp"

class ObjectEntity : public Entity {
public:
    void spawnObjectEntity(const std::string& spritePath, float posX, float posY,
                           int spriteX, int spriteY, int spriteWidth, int spriteHeight);

    void changeInInventory() override;
    bool getInInventory() override;

private:
    std::shared_ptr<BoundsComponent> bounds;
    std::shared_ptr<SpriteComponent> sprite;
    std::shared_ptr<TransformComponent> transform;
    std::shared_ptr<CollisionComponent> collision;

    bool inInventory = false;
};
