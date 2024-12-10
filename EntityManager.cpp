#include <filesystem>
#include "EntityManager.hpp"
#include "Components/BoundsComponent.hpp"
#include "Components/InputComponent.hpp"
#include "Components/SpriteComponent.hpp"
#include "Components/TransformComponent.hpp"
#include "Components/CollisionComponent.hpp"
#include "Components/DescriptionComponent.hpp"

void EntityManager::spawnPlayerEntity(const std::shared_ptr<PlayerEntity>& player, const std::string &spritePath,
                                      float posX, float posY, int spriteX, int spriteY, int spriteWidth,
                                      int spriteHeight) {
    player->transform = std::make_shared<TransformComponent>();
    player->sprite = std::make_shared<SpriteComponent>(std::filesystem::current_path().string() + spritePath,
                                                       spriteX, spriteY, spriteWidth, spriteHeight);
    player->bounds = std::make_shared<BoundsComponent>();
    player->input = std::make_shared<InputComponent>();
    player->collision = std::make_shared<CollisionComponent>();

    player->transform->setPosition(posX, posY);
    player->bounds->setBounds(player->sprite->getSprite());

    player->input->setKey(sf::Keyboard::W, false);
    player->input->setKey(sf::Keyboard::S, false);
    player->input->setKey(sf::Keyboard::A, false);
    player->input->setKey(sf::Keyboard::D, false);
    player->input->setKey(sf::Keyboard::F, false);

    player->addComponent(player->transform);
    player->addComponent(player->sprite);
    player->addComponent(player->bounds);
    player->addComponent(player->input);
    player->addComponent(player->collision);

    player->ID = 1;
    player->flag = PLAYER;
}

void EntityManager::spawnInventoryEntity(const std::shared_ptr<InventoryEntity>& inventory, const std::string &spritePath,
                                         float posX, float posY, int spriteX, int spriteY, int spriteWidth,
                                         int spriteHeight) {
    inventory->transform = std::make_shared<TransformComponent>();
    inventory->sprite = std::make_shared<SpriteComponent>(std::filesystem::current_path().string() + spritePath,
                                                          spriteX, spriteY, spriteWidth, spriteHeight);
    inventory->sprite->setScale(spriteWidth, spriteHeight * 1.25);
    inventory->input = std::make_shared<InputComponent>();

    inventory->transform->setPosition(posX, posY);

    inventory->input->setKey(sf::Keyboard::E, false);

    inventory->addComponent(inventory->transform);
    inventory->addComponent(inventory->sprite);
    inventory->addComponent(inventory->input);

    inventory->ID = 0;
    inventory->flag = INVENTORY;
}

void EntityManager::spawnObjectEntity(const std::shared_ptr<ObjectEntity>& object, const std::string &spritePath, float posX,
                                      float posY, int spriteX, int spriteY, int spriteWidth, int spriteHeight,
                                      std::string script, sf::Font& font) {
    object->transform = std::make_shared<TransformComponent>();
    object->sprite = std::make_shared<SpriteComponent>(std::filesystem::current_path().string() + spritePath,
                                                       spriteX, spriteY, spriteWidth, spriteHeight);
    object->bounds = std::make_shared<BoundsComponent>();
    object->collision = std::make_shared<CollisionComponent>();
    object->description = std::make_shared<DescriptionComponent>(posX, posY, script, font);

    object->transform->setPosition(posX, posY);
    object->bounds->setBounds(object->sprite->getSprite());

    object->addComponent(object->transform);
    object->addComponent(object->sprite);
    object->addComponent(object->collision);
    object->addComponent(object->description);
    object->addComponent(object->bounds);

    object->ID = 1;
    object->flag = OBJECT;
}

void EntityManager::spawnInteractiveObjectEntity(const std::shared_ptr<InteractiveObjectEntity>& interactiveObject, const std::string& spritePath,
                                  float posX, float posY, int spriteX, int spriteY, int spriteWidth, int spriteHeight,
                                  std::string script, sf::Font& font) {
    interactiveObject->transform = std::make_shared<TransformComponent>();
    interactiveObject->sprite = std::make_shared<SpriteComponent>(std::filesystem::current_path().string() + spritePath,
                                                       spriteX, spriteY, spriteWidth, spriteHeight);
    interactiveObject->bounds = std::make_shared<BoundsComponent>();
    interactiveObject->collision = std::make_shared<CollisionComponent>();
    interactiveObject->description = std::make_shared<DescriptionComponent>(posX, posY, script, font);

    interactiveObject->transform->setPosition(posX, posY);
    interactiveObject->bounds->setBounds(interactiveObject->sprite->getSprite());

    interactiveObject->addComponent(interactiveObject->transform);
    interactiveObject->addComponent(interactiveObject->sprite);
    interactiveObject->addComponent(interactiveObject->collision);
    interactiveObject->addComponent(interactiveObject->description);
    interactiveObject->addComponent(interactiveObject->bounds);

    interactiveObject->ID = 1;
    interactiveObject->flag = INTERACTIVE_OBJECT;
}
