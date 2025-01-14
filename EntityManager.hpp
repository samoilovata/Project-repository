#pragma once
#include <string>
#include <memory>
#include <unordered_map>
#include "Entities/PlayerEntity.hpp"
#include "Entities/InventoryEntity.hpp"
#include "Entities/ObjectEntity.hpp"
#include "Entities/InteractiveObjectEntity.hpp"
#include "Entities/LocationObjectEntity.hpp"
#include "Entities/StaticObjectEntity.hpp"

struct Location {
    sf::Vector2f playerDefaultPosition;

    sf::Sprite backgroundSprite;
    std::shared_ptr<sf::Texture> backgroundTexture;
};

class EntityManager {
public:
    static inline std::unordered_map<sf::Keyboard::Key, bool> keyStatus;
    static inline std::unordered_map<int, std::shared_ptr<Location>> locationStatus;

    std::shared_ptr<PlayerEntity> playerPtr;
    std::vector<std::shared_ptr<Entity>> entities;
    std::vector<std::shared_ptr<Entity>> inventory;

    int currentLocation = 1;
    int scriptStatus = 0;

    void spawnLocation(const std::string& fileName, sf::Vector2f position, sf::Vector2f playerPosition, int ID);

    void spawnPlayerEntity(const std::shared_ptr<PlayerEntity>& player, const std::string& spritePath, float posX, float posY,
                           int spriteX, int spriteY, int spriteWidth, int spriteHeight);
    void spawnInventoryEntity(const std::shared_ptr<InventoryEntity>& inventory, const std::string& spritePath, float posX, float posY,
                              int spriteX, int spriteY, int spriteWidth, int spriteHeight);
    void spawnObjectEntity(const std::shared_ptr<ObjectEntity>& object, const std::string& spritePath, float posX,
                           float posY, int spriteX, int spriteY, int spriteWidth, int spriteHeight, sf::String script, sf::Font& font, int loc);
    void spawnInteractiveObjectEntity(const std::shared_ptr<InteractiveObjectEntity>& interactiveObject, const std::string& spritePath,
                                      float posX, float posY, int spriteX, int spriteY, int spriteWidth, int spriteHeight,
                                      sf::String script, sf::Font& font, int loc);
    void spawnLocationObjectEntity(const std::shared_ptr<LocationObjectEntity>& locationObject, float posX, float posY,
                                   int boundsWidth, int boundsHeight, sf::String script, sf::Font& font, int loc);
    void spawnStaticObjectEntity(const std::shared_ptr<StaticObjectEntity>& object, const std::string& spritePath, float posX,
                           float posY, int spriteX, int spriteY, int spriteWidth, int spriteHeight, int loc);
};
