#include "MoveSystem.hpp"

void MoveSystem::update(EntityManager& entityManager, sf::Time& deltaTime) {
    auto transformComponent = entityManager.playerPtr->getComponent<TransformComponent>();
    auto spriteComponent = entityManager.playerPtr->getComponent<SpriteComponent>();
    auto boundsComponent = entityManager.playerPtr->getComponent<BoundsComponent>();

    sf::RectangleShape tempRect {sf::Vector2f (boundsComponent->getBounds().width - 30, boundsComponent->getBounds().height - 120)};
    tempRect.setPosition(sf::Vector2f (transformComponent->getPosition().x + 15, transformComponent->getPosition().y + 110));

    for (const auto& entity : entityManager.entities) {
        if (entity == entityManager.playerPtr) continue;

        auto entityBoundsComponent = entity->getComponent<BoundsComponent>();

        tempRect.move(sf::Vector2f (0, -3));
        if (entityBoundsComponent && (entity->location == entityManager.currentLocation || entity->location == 0))
            if (tempRect.getGlobalBounds().intersects(entityBoundsComponent->getBounds())) up = true;

        tempRect.move(sf::Vector2f (0, 6));
        if (entityBoundsComponent && (entity->location == entityManager.currentLocation || entity->location == 0))
            if (tempRect.getGlobalBounds().intersects(entityBoundsComponent->getBounds())) down = true;

        tempRect.move(sf::Vector2f (-3, -3));
        if (entityBoundsComponent && (entity->location == entityManager.currentLocation || entity->location == 0))
            if (tempRect.getGlobalBounds().intersects(entityBoundsComponent->getBounds())) left = true;

        tempRect.move(sf::Vector2f (6, 0));
        if (entityBoundsComponent && (entity->location == entityManager.currentLocation || entity->location == 0))
            if (tempRect.getGlobalBounds().intersects(entityBoundsComponent->getBounds())) right = true;

        tempRect.move(sf::Vector2f (-3, 0));
    }

    if (transformComponent && spriteComponent) {
        if (frame % 20 == 0) currentFrame++;
        if (currentFrame == 4) currentFrame -= 4;

        if (EntityManager::keyStatus[sf::Keyboard::W]) {
            spriteComponent->getSprite().setTextureRect(sf::IntRect(int(currentFrame) * 20, 35, 20, 28));
            if (up) up = false;
            else transformComponent->translate(sf::Vector2f(0, -3));
        }

        if (EntityManager::keyStatus[sf::Keyboard::S]) {
            spriteComponent->getSprite().setTextureRect(sf::IntRect(int(currentFrame) * 20, 3, 20, 28));
            if (down) down = false;
            else transformComponent->translate(sf::Vector2f(0, 3));
        }

        if (EntityManager::keyStatus[sf::Keyboard::A]) {
            spriteComponent->getSprite().setTextureRect(sf::IntRect(int(currentFrame) * 20, 99, 20, 29));
            if (left) left = false;
            else transformComponent->translate(sf::Vector2f(-3, 0));
        }

        if (EntityManager::keyStatus[sf::Keyboard::D]) {
            spriteComponent->getSprite().setTextureRect(sf::IntRect(int(currentFrame) * 20, 67, 20, 29));
            if (right) right = false;
            else transformComponent->translate(sf::Vector2f(3, 0));
        }

        frame++;
        if (frame == 61) frame = 1;
    }
}