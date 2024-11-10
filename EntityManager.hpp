#pragma once
#include <string>
#include <memory>
#include "Entities/PlayerEntity.hpp"
#include "Entities/InventoryEntity.hpp"
#include "Entities/ObjectEntity.hpp"

class EntityManager {
public:
    static void spawnPlayerEntity(const std::shared_ptr<PlayerEntity>& player, const std::string &spritePath, float posX, float posY,
                           int spriteX, int spriteY, int spriteWidth, int spriteHeight);
    static void spawnInventoryEntity(const std::shared_ptr<InventoryEntity>& inventory, const std::string& spritePath, float posX, float posY,
                              int spriteX, int spriteY, int spriteWidth, int spriteHeight);
    static void spawnObjectEntity(const std::shared_ptr<ObjectEntity>& object, const std::string& spritePath, float posX, float posY,
                           int spriteX, int spriteY, int spriteWidth, int spriteHeight);
};
