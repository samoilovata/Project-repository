#include <filesystem>
#include "InventoryEntity.hpp"

void InventoryEntity::spawnInventoryEntity(const std::string &spritePath, float posX, float posY, int spriteX, int spriteY,
                                           int spriteWidth, int spriteHeight) {
    ID = 1;

    transform = std::make_shared<TransformComponent>();
    sprite = std::make_shared<SpriteComponent>(std::filesystem::current_path().string() + spritePath,
                                                    spriteX, spriteY, spriteWidth, spriteHeight);
    sprite->setScale(spriteWidth, spriteHeight);
    input = std::make_shared<InputComponent>();

    transform->setPosition(posX, posY);

    input->setKey(sf::Keyboard::E, false);

    addComponent(transform);
    addComponent(sprite);
    addComponent(input);

    changeValue();
}
