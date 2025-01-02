#include "MoveSystem.hpp"

void MoveSystem::update(EntityManager& entityManager, sf::Time& deltaTime) {
    auto transformComponent = entityManager.playerPtr->getComponent<TransformComponent>();
    auto spriteComponent = entityManager.playerPtr->getComponent<SpriteComponent>();

    if (transformComponent && spriteComponent) {
        if (frame % 20 == 0) currentFrame++;
        if (currentFrame == 4) currentFrame -= 4;

        if (EntityManager::keyStatus[sf::Keyboard::W]) {
            spriteComponent->getSprite().setTextureRect(sf::IntRect(int(currentFrame) * 200, 330, 200, 320));
            if (collisionComponent->getCollision() && move.first == 0 && move.second == -1) {
                transformComponent->translate(sf::Vector2f(0, 0));
            }
            else transformComponent->translate(sf::Vector2f(0, -4));
            move = {0, -1};
        }

        if (EntityManager::keyStatus[sf::Keyboard::S]) {
            spriteComponent->getSprite().setTextureRect(sf::IntRect(int(currentFrame) * 200, 0, 200, 320));
            if (collisionComponent->getCollision() && move.first == 0 && move.second == 1) {
                transformComponent->translate(sf::Vector2f(0, 0));
            }
            else transformComponent->translate(sf::Vector2f(0, 4));
            move = {0, 1};
        }

        if (EntityManager::keyStatus[sf::Keyboard::A]) {
            spriteComponent->getSprite().setTextureRect(sf::IntRect(int(currentFrame) * 200, 980, 200, 320));
            if (collisionComponent->getCollision() && move.first == -1 && move.second == 0) {
                transformComponent->translate(sf::Vector2f(0, 0));
            }
            else transformComponent->translate(sf::Vector2f(-4, 0));
            move = {-1, 0};
        }

        if (EntityManager::keyStatus[sf::Keyboard::D]) {
            spriteComponent->getSprite().setTextureRect(sf::IntRect(int(currentFrame) * 200, 660, 200, 320));
            if (collisionComponent->getCollision() && move.first == 1 && move.second == 0) {
                transformComponent->translate(sf::Vector2f(0, 0));
            }
            else transformComponent->translate(sf::Vector2f(4, 0));
            move = {1, 0};
        }

        frame++;
        if (frame == 61) frame = 1;
    }
}