#include <iostream>
#include <filesystem>
#include "Engine.hpp"
#include "ECS/Entity.hpp"
#include "Components/TransformComponent.hpp"
#include "Components/SpriteComponent.hpp"
#include "Components/BoundsComponent.hpp"
#include "Components/InputComponent.hpp"

class SpawnEntity {
public:
    SpawnEntity(const std::shared_ptr<Entity>& entity, const std::string& spritePath, float posX, float posY,
                float spriteX, float spriteY, float spriteWidth, float spriteHeight);
};

class SpawnEntityInventory {
public:
    SpawnEntityInventory(const std::shared_ptr<Entity>& entity, const std::string& spritePath, float posX, float posY,
                      float spriteX, float spriteY, float spriteWidth, float spriteHeight);
};
