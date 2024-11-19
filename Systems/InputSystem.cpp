#include <SFML/Window/Keyboard.hpp>
#include "InputSystem.hpp"
#include "../Components/TransformComponent.hpp"
#include "../Components/SpriteComponent.hpp"
#include "../Components/InputComponent.hpp"
#include "../Components/CollisionComponent.hpp"

void InputSystem::update(EntityManager entityManager, sf::Time& deltaTime) {
    for (auto &entity : entityManager.entities) {
        auto transformComponent = entity->getComponent<TransformComponent>();
        auto spriteComponent = entity->getComponent<SpriteComponent>();
        auto inputComponent = entity->getComponent<InputComponent>();

        if (transformComponent && inputComponent) {
            if (frame % 20 == 0) currentFrame++;
            if (currentFrame == 4) currentFrame -= 4;

            if (inputComponent->keyPressed(sf::Keyboard::W)) {
                spriteComponent->getSprite().setTextureRect(sf::IntRect (int(currentFrame) * 200, 330, 200, 320));
                transformComponent->translate(sf::Vector2f(0, -4));
            }

            if (inputComponent->keyPressed(sf::Keyboard::S)) {
                spriteComponent->getSprite().setTextureRect(sf::IntRect (int(currentFrame) * 200, 0, 200, 320));
                transformComponent->translate(sf::Vector2f(0, 4));
            }

            if (inputComponent->keyPressed(sf::Keyboard::A)) {
                spriteComponent->getSprite().setTextureRect(sf::IntRect (int(currentFrame) * 200, 980, 200, 320));
                transformComponent->translate(sf::Vector2f(-4, 0));
            }

            if (inputComponent->keyPressed(sf::Keyboard::D)) {
                spriteComponent->getSprite().setTextureRect(sf::IntRect (int(currentFrame) * 200, 660, 200, 320));
                transformComponent->translate(sf::Vector2f(4, 0));
            }

            frame++;
            if (frame == 61) frame = 1;

            if (inputComponent->keyPressed(sf::Keyboard::E) && !IDManager::getIsRender(entity->ID)) {
                IDManager::changeIsRender(entity->ID);
                inputComponent->updateKey(sf::Keyboard::E, false);
            } else if (inputComponent->keyPressed(sf::Keyboard::E) && IDManager::getIsRender(entity->ID)) {
                IDManager::changeIsRender(entity->ID);
                inputComponent->updateKey(sf::Keyboard::E, false);
            }

            if (inputComponent->keyPressed(sf::Keyboard::F)) {
                for (auto &objectEntity : entityManager.entities) {
                    if (objectEntity->flag == OBJECT && objectEntity->getComponent<CollisionComponent>()->getCollision()) {
                        IDManager::changeIsRender(objectEntity->ID);
                        IDManager::changeInInventory(objectEntity->ID);
                        objectEntity->getComponent<TransformComponent>()->setPosition(265, 220);
//                      objectEntity->getComponent<SpriteComponent>()->setPosition(что-то, что-то);
                    }
                }
            }
        }
    }
}
