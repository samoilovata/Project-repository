#include <iostream>
#include <filesystem>
#include "ECS/Entity.hpp"
#include "Components/TransformComponent.hpp"
#include "Components/SpriteComponent.hpp"
#include "Components/BoundsComponent.hpp"
#include "Components/InputComponent.hpp"


class SpawnEntity {
public:
    SpawnEntity(const std::string& spritePath, float posX, float posY,
                float spriteX, float spriteY, float spriteWidth, float spriteHeight);

    std::shared_ptr<Entity> getEntity() const;

private:
    std::shared_ptr<Entity> entity;
};



