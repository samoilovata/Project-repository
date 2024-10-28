#include <filesystem>
#include <algorithm>
#include "InventoryEntity.hpp"

void InventoryEntity::spawnInventoryEntity(const std::string &spritePath, float posX, float posY, int spriteX, int spriteY,
                                           int spriteWidth, int spriteHeight) {
    transform = std::make_shared<TransformComponent>();
    sprite = std::make_shared<SpriteComponent>(std::filesystem::current_path().string() + spritePath,
                                                    spriteX, spriteY, spriteWidth, spriteHeight);
    sprite->setScale(spriteWidth, spriteHeight);
    bounds = std::make_shared<BoundsComponent>();
    input = std::make_shared<InputComponent>();

    transform->setPosition(posX, posY);
    bounds->setBounds(sprite->getSprite());

    input->setKey(sf::Keyboard::E, false);

    addComponent(transform);
    addComponent(sprite);
    addComponent(bounds);
    addComponent(input);

    changeValue();
}

void InventoryEntity::addObjectInInventory(std::shared_ptr<Entity> object) {
    inventory.push_back(object);
}

void InventoryEntity::removeObjectsFromInventory(std::shared_ptr<Entity> object) {
    inventory.erase(inventory.begin());
}

void InventoryEntity::swapObjectsInInventory(std::shared_ptr<Entity> object) {
    std::swap(*inventory.begin(), *std::find(inventory.begin(), inventory.end(),object));
}
