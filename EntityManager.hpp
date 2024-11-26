#pragma once
#include <string>
#include <memory>
#include "Entities/PlayerEntity.hpp"
#include "Entities/InventoryEntity.hpp"
#include "Entities/ObjectEntity.hpp"

class EntityManager {
public:
    std::vector<std::shared_ptr<Entity>> entities;
    std::vector<std::shared_ptr<Entity>> inventory;

    std::shared_ptr<Entity> activeSlot;
    void updateActiveSlot();

    void spawnPlayerEntity(const std::shared_ptr<PlayerEntity>& player, const std::string &spritePath, float posX, float posY,
                           int spriteX, int spriteY, int spriteWidth, int spriteHeight);
    void spawnInventoryEntity(const std::shared_ptr<InventoryEntity>& inventory, const std::string& spritePath, float posX, float posY,
                              int spriteX, int spriteY, int spriteWidth, int spriteHeight);
    void spawnObjectEntity(const std::shared_ptr<ObjectEntity>& object, const std::string &spritePath, float posX,
                           float posY, int spriteX, int spriteY, int spriteWidth, int spriteHeight,
                           int descriptionHeight, int descriptionWidth, int descriptionX, int descriptionY);
};
