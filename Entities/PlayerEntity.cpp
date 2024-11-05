#include <filesystem>
#include "PlayerEntity.hpp"

void PlayerEntity::spawnPlayerEntity(const std::string &spritePath, float posX, float posY, int spriteX, int spriteY, int spriteWidth,
                           int spriteHeight) {
    ID = 0;
    flag = player;

    collision = std::make_shared<CollisionComponent>();
    transform = std::make_shared<TransformComponent>();
    sprite = std::make_shared<SpriteComponent>(std::filesystem::current_path().string() + spritePath,
                                                    spriteX, spriteY, spriteWidth, spriteHeight);
    bounds = std::make_shared<BoundsComponent>();
    input = std::make_shared<InputComponent>();

    transform->setPosition(posX, posY);
    bounds->setBounds(sprite->getSprite());

    input->setKey(sf::Keyboard::W, false);
    input->setKey(sf::Keyboard::S, false);
    input->setKey(sf::Keyboard::A, false);
    input->setKey(sf::Keyboard::D, false);
    input->setKey(sf::Keyboard::F, false);

    addComponent(transform);
    addComponent(sprite);
    addComponent(bounds);
    addComponent(input);
    addComponent(collision);
}
