#include "MoveSystem.hpp"

void MoveSystem::update(EntityManager& entityManager, sf::Time& deltaTime) {
    auto transformComponent = entityManager.playerPtr->getComponent<TransformComponent>();
    auto spriteComponent = entityManager.playerPtr->getComponent<SpriteComponent>();
    auto boundsComponent = entityManager.playerPtr->getComponent<BoundsComponent>();

    sf::RectangleShape tempRect {sf::Vector2f (boundsComponent->getBounds().width - 80, boundsComponent->getBounds().height - 240)};
    tempRect.setPosition(sf::Vector2f (transformComponent->getPosition().x + 40, transformComponent->getPosition().y + 235));

    for (const auto& entity : entityManager.entities) {
        if (entity == entityManager.playerPtr) continue;

        auto entityBoundsComponent = entity->getComponent<BoundsComponent>();

        tempRect.setPosition(tempRect.getPosition() + sf::Vector2f (0, -4));
        if (entityBoundsComponent && (entity->location == entityManager.currentLocation || entity->location == 0))
            if (tempRect.getGlobalBounds().intersects(entityBoundsComponent->getBounds())) up = true;

        tempRect.setPosition(tempRect.getPosition() + sf::Vector2f (0, 8));
        if (entityBoundsComponent && (entity->location == entityManager.currentLocation || entity->location == 0))
            if (tempRect.getGlobalBounds().intersects(entityBoundsComponent->getBounds())) down = true;

        tempRect.setPosition(tempRect.getPosition() + sf::Vector2f (-4, -4));
        if (entityBoundsComponent && (entity->location == entityManager.currentLocation || entity->location == 0))
            if (tempRect.getGlobalBounds().intersects(entityBoundsComponent->getBounds())) left = true;

        tempRect.setPosition(tempRect.getPosition() + sf::Vector2f (8, 0));
        if (entityBoundsComponent && (entity->location == entityManager.currentLocation || entity->location == 0))
            if (tempRect.getGlobalBounds().intersects(entityBoundsComponent->getBounds())) right = true;
    }

    if (transformComponent && spriteComponent) {
        if (frame % 20 == 0) currentFrame++;
        if (currentFrame == 4) currentFrame -= 4;

        if (EntityManager::keyStatus[sf::Keyboard::W]) {
            spriteComponent->getSprite().setTextureRect(sf::IntRect(int(currentFrame) * 200, 350, 200, 280));
            if (up) up = false;
            else transformComponent->translate(sf::Vector2f(0, -4));
        }

        if (EntityManager::keyStatus[sf::Keyboard::S]) {
            spriteComponent->getSprite().setTextureRect(sf::IntRect(int(currentFrame) * 200, 30, 200, 280));
            if (down) down = false;
            else transformComponent->translate(sf::Vector2f(0, 4));
        }

        if (EntityManager::keyStatus[sf::Keyboard::A]) {
            spriteComponent->getSprite().setTextureRect(sf::IntRect(int(currentFrame) * 200, 990, 200, 290));
            if (left) left = false;
            else transformComponent->translate(sf::Vector2f(-4, 0));
        }

        if (EntityManager::keyStatus[sf::Keyboard::D]) {
            spriteComponent->getSprite().setTextureRect(sf::IntRect(int(currentFrame) * 200, 670, 200, 290));
            if (right) right = false;
            else transformComponent->translate(sf::Vector2f(4, 0));
        }

        frame++;
        if (frame == 61) frame = 1;
    }
}