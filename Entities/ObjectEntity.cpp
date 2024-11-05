#include <filesystem>
#include "ObjectEntity.hpp"

void ObjectEntity::spawnObjectEntity(const std::string &spritePath, float posX, float posY, int spriteX, int spriteY,
                                     int spriteWidth, int spriteHeight) {
    ID = 2;

    collision = std::make_shared<CollisionComponent>();
    transform = std::make_shared<TransformComponent>();
    sprite = std::make_shared<SpriteComponent>(std::filesystem::current_path().string() + spritePath,
                                               spriteX, spriteY, spriteWidth, spriteHeight);
    bounds = std::make_shared<BoundsComponent>();

    transform->setPosition(posX, posY);
    bounds->setBounds(sprite->getSprite());

    addComponent(transform);
    addComponent(sprite);
    addComponent(bounds);
    addComponent(collision);
}

bool ObjectEntity::getInInventory() {
    return inInventory;
}

void ObjectEntity::changeInInventory() {
    if (!inInventory) inInventory = true;
    else inInventory = false;
}
