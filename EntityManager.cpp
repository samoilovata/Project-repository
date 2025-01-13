#include <filesystem>
#include "EntityManager.hpp"
#include "Components/BoundsComponent.hpp"
#include "Components/SpriteComponent.hpp"
#include "Components/TransformComponent.hpp"
#include "Components/CollisionComponent.hpp"
#include "Components/DescriptionComponent.hpp"

void EntityManager::spawnLocation(const std::string& fileName, sf::Vector2f position, sf::Vector2f playerPosition, int ID) {
    auto loc = std::make_shared<Location>();
    loc->backgroundTexture = std::make_shared<sf::Texture>();

    if (!loc->backgroundTexture->loadFromFile(std::filesystem::current_path().string() + fileName)) {
        std::cerr << "Failed to load background image!" << std::endl;
    }

    loc->backgroundSprite.setTexture(*loc->backgroundTexture);
    loc->backgroundSprite.setPosition(position);
    loc->backgroundSprite.setScale(5, 5);

    loc->playerDefaultPosition = playerPosition;

    locationStatus[ID] = loc;
}

void EntityManager::spawnPlayerEntity(const std::shared_ptr<PlayerEntity>& player, const std::string& spritePath,
                                      float posX, float posY, int spriteX, int spriteY, int spriteWidth,
                                      int spriteHeight) {
    player->transform = std::make_shared<TransformComponent>();
    player->sprite = std::make_shared<SpriteComponent>(std::filesystem::current_path().string() + spritePath,
                                                       spriteX, spriteY, spriteWidth, spriteHeight);
    player->bounds = std::make_shared<BoundsComponent>();
    player->collision = std::make_shared<CollisionComponent>();

    player->transform->setPosition(posX, posY);
    player->bounds->setBounds(player->sprite->getSprite());

    player->addComponent(player->transform);
    player->addComponent(player->sprite);
    player->addComponent(player->bounds);
    player->addComponent(player->collision);

    player->ID = 1;
    player->location = 0;
    player->flag = PLAYER;
}

void EntityManager::spawnInventoryEntity(const std::shared_ptr<InventoryEntity>& inventory, const std::string &spritePath,
                                         float posX, float posY, int spriteX, int spriteY, int spriteWidth,
                                         int spriteHeight) {
    inventory->transform = std::make_shared<TransformComponent>();
    inventory->sprite = std::make_shared<SpriteComponent>(std::filesystem::current_path().string() + spritePath,
                                                          spriteX, spriteY, spriteWidth, spriteHeight);
    inventory->sprite->sprite.setScale(1, 1);
    inventory->transform->setPosition(posX, posY);

    inventory->addComponent(inventory->transform);
    inventory->addComponent(inventory->sprite);

    inventory->ID = 0;
    inventory->location = 0;
    inventory->flag = INVENTORY;
}

void EntityManager::spawnObjectEntity(const std::shared_ptr<ObjectEntity>& object, const std::string &spritePath, float posX,
                                      float posY, int spriteX, int spriteY, int spriteWidth, int spriteHeight,
                                      sf::String script, sf::Font& font, int loc) {
    object->transform = std::make_shared<TransformComponent>();
    object->sprite = std::make_shared<SpriteComponent>(std::filesystem::current_path().string() + spritePath,
                                                       spriteX, spriteY, spriteWidth, spriteHeight);
    object->bounds = std::make_shared<BoundsComponent>();
    object->collision = std::make_shared<CollisionComponent>();
    object->description = std::make_shared<DescriptionComponent>(posX, posY, spriteWidth, script, font);

    object->transform->setPosition(posX, posY);
    object->bounds->setBounds(object->sprite->getSprite());

    object->addComponent(object->transform);
    object->addComponent(object->sprite);
    object->addComponent(object->collision);
    object->addComponent(object->description);
    object->addComponent(object->bounds);

    object->ID = 1;
    object->location = loc;
    object->flag = OBJECT;
}

void EntityManager::spawnInteractiveObjectEntity(const std::shared_ptr<InteractiveObjectEntity>& interactiveObject, const std::string& spritePath,
                                  float posX, float posY, int spriteX, int spriteY, int spriteWidth, int spriteHeight,
                                  sf::String script, sf::Font& font, int loc) {
    interactiveObject->transform = std::make_shared<TransformComponent>();
    interactiveObject->sprite = std::make_shared<SpriteComponent>(std::filesystem::current_path().string() + spritePath,
                                                       spriteX, spriteY, spriteWidth, spriteHeight);
    interactiveObject->bounds = std::make_shared<BoundsComponent>();
    interactiveObject->collision = std::make_shared<CollisionComponent>();
    interactiveObject->description = std::make_shared<DescriptionComponent>(posX, posY, spriteWidth, script, font);

    interactiveObject->transform->setPosition(posX, posY);
    interactiveObject->bounds->setBounds(interactiveObject->sprite->getSprite());

    interactiveObject->addComponent(interactiveObject->transform);
    interactiveObject->addComponent(interactiveObject->sprite);
    interactiveObject->addComponent(interactiveObject->collision);
    interactiveObject->addComponent(interactiveObject->description);
    interactiveObject->addComponent(interactiveObject->bounds);

    interactiveObject->ID = 1;
    interactiveObject->location = loc;
    interactiveObject->flag = INTERACTIVE_OBJECT;
}

void EntityManager:: spawnLocationObjectEntity(const std::shared_ptr<LocationObjectEntity>& locationObject, float posX, float posY,
                                               int boundsWidth, int boundsHeight, sf::String script, sf::Font& font, int loc) {
    locationObject->transform = std::make_shared<TransformComponent>();
    locationObject->bounds = std::make_shared<BoundsComponent>();
    locationObject->collision = std::make_shared<CollisionComponent>();
    locationObject->description = std::make_shared<DescriptionComponent>(posX, posY, boundsWidth / 5, script, font);

    locationObject->transform->setPosition(posX, posY);
    locationObject->bounds->setBounds(sf::Vector2f (posX, posY), sf::Vector2f (boundsWidth, boundsHeight));

    locationObject->addComponent(locationObject->transform);
    locationObject->addComponent(locationObject->collision);
    locationObject->addComponent(locationObject->description);
    locationObject->addComponent(locationObject->bounds);

    locationObject->ID = 1;
    locationObject->location = loc;
    locationObject->flag = LOCATION_OBJECT;
}

void EntityManager::spawnStaticObjectEntity(const std::shared_ptr<StaticObjectEntity> &staticObject, const std::string &spritePath,
                                       float posX, float posY, int spriteX, int spriteY, int spriteWidth,
                                       int spriteHeight, int loc) {
    staticObject->transform = std::make_shared<TransformComponent>();
    staticObject->sprite = std::make_shared<SpriteComponent>(std::filesystem::current_path().string() + spritePath,
                                                       spriteX, spriteY, spriteWidth, spriteHeight);
    staticObject->bounds = std::make_shared<BoundsComponent>();
    staticObject->collision = std::make_shared<CollisionComponent>();

    staticObject->transform->setPosition(posX, posY);
    staticObject->bounds->setBounds(staticObject->sprite->getSprite());

    staticObject->addComponent(staticObject->transform);
    staticObject->addComponent(staticObject->sprite);
    staticObject->addComponent(staticObject->collision);
    staticObject->addComponent(staticObject->bounds);

    staticObject->ID = 1;
    staticObject->location = loc;
    staticObject->flag = STATIC_OBJECT;
}
