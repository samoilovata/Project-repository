#pragma once
#include <string>
#include <memory>
#include <unordered_map>
#include "Entities/PlayerEntity.hpp"
#include "Entities/InventoryEntity.hpp"
#include "Entities/ObjectEntity.hpp"
#include "Entities/InteractiveObjectEntity.hpp"
#include "Entities/LocationObject.hpp"

class EntityManager {
public:
    static inline std::unordered_map<sf::Keyboard::Key, bool> keyStatus;
    std::vector<std::shared_ptr<Entity>> entities;
    std::vector<std::shared_ptr<Entity>> inventory;

    int currentLocation = 1;

    void spawnPlayerEntity(const std::shared_ptr<PlayerEntity>& player, const std::string& spritePath, float posX, float posY,
                           int spriteX, int spriteY, int spriteWidth, int spriteHeight);
    void spawnInventoryEntity(const std::shared_ptr<InventoryEntity>& inventory, const std::string& spritePath, float posX, float posY,
                              int spriteX, int spriteY, int spriteWidth, int spriteHeight);
    void spawnObjectEntity(const std::shared_ptr<ObjectEntity>& object, const std::string& spritePath, float posX,
                           float posY, int spriteX, int spriteY, int spriteWidth, int spriteHeight, sf::String script, sf::Font& font, int loc);
    void spawnInteractiveObjectEntity(const std::shared_ptr<InteractiveObjectEntity>& interactiveObject, const std::string& spritePath,
                                      float posX, float posY, int spriteX, int spriteY, int spriteWidth, int spriteHeight,
                                      sf::String script, sf::Font& font, int loc);
    void spawnLocationObjectEntity(const std::shared_ptr<LocationObject>& locationObject, const std::string& spritePath,
                                      float posX, float posY, int spriteX, int spriteY, int spriteWidth, int spriteHeight,
                                      sf::String script, sf::Font& font, int loc);
};
