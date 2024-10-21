#include "SpawnEntity.hpp"

SpawnEntity::SpawnEntity(std::shared_ptr<Entity> entity, const std::string &spritePath, float posX, float posY, float spriteX, float spriteY,
                         float spriteWidth, float spriteHeight) {

    auto transform = std::make_shared<TransformComponent>();
    auto sprite = std::make_shared<SpriteComponent>(std::filesystem::current_path().string() + spritePath,
                                                    spriteX, spriteY, spriteWidth, spriteHeight);
    auto bounds = std::make_shared<BoundsComponent>();
    [[maybe_unused]] auto inputComponent = std::make_shared<InputComponent>();
    transform->setPosition(posX, posY);
    bounds->setBounds(sprite->getSprite());

    inputComponent->setKey(sf::Keyboard::W, false);
    inputComponent->setKey(sf::Keyboard::S, false);
    inputComponent->setKey(sf::Keyboard::A, false);
    inputComponent->setKey(sf::Keyboard::D, false);
    inputComponent->setKey(sf::Keyboard::F, false);

    entity->addComponent(transform);
    entity->addComponent(sprite);
    entity->addComponent(bounds);
    entity->addComponent(inputComponent);
}

