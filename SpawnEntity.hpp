#include <iostream>
#include <filesystem>
#include "ECS/Entity.hpp"
#include "Engine.hpp"
#include "Components/TransformComponent.hpp"
#include "Components/SpriteComponent.hpp"
#include "Components/BoundsComponent.hpp"
#include "Components/InputComponent.hpp"

class SpawnEntity {
public:
    SpawnEntity(std::shared_ptr<Entity> entity, const std::string& spritePath, float posX, float posY,
                float spriteX, float spriteY, float spriteWidth, float spriteHeight);
};
