#pragma once
#include <string>
#include <memory>
#include "Entities/PlayerEntity.hpp"
#include "Entities/InventoryEntity.hpp"
#include "Entities/ObjectEntity.hpp"
#include "Entities/InteractiveObjectEntity.hpp"

class EntityManager {
public:
    std::vector<std::shared_ptr<Entity>> entities;
    std::vector<std::shared_ptr<Entity>> inventory;

    void spawnPlayerEntity(const std::shared_ptr<PlayerEntity>& player, const std::string& spritePath, float posX, float posY,
                           int spriteX, int spriteY, int spriteWidth, int spriteHeight);
    void spawnInventoryEntity(const std::shared_ptr<InventoryEntity>& inventory, const std::string& spritePath, float posX, float posY,
                              int spriteX, int spriteY, int spriteWidth, int spriteHeight);
    void spawnObjectEntity(const std::shared_ptr<ObjectEntity>& object, const std::string& spritePath, float posX,
                           float posY, int spriteX, int spriteY, int spriteWidth, int spriteHeight, std::string script, sf::Font& font);
    void spawnInteractiveObjectEntity(const std::shared_ptr<InteractiveObjectEntity>& interactiveObject, const std::string& spritePath,
                                      float posX, float posY, int spriteX, int spriteY, int spriteWidth, int spriteHeight,
                                      std::string script, sf::Font& font);
};
