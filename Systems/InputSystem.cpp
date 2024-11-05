#include <SFML/Window/Keyboard.hpp>
#include "InputSystem.hpp"
#include "../Components/TransformComponent.hpp"
#include "../Components/SpriteComponent.hpp"
#include "../Components/InputComponent.hpp"

void InputSystem::update(float time, sf::Time& deltaTime) {
    for (auto &entity : vectorEntity) {
        auto transformComponent = entity->getComponent<TransformComponent>();
        auto spriteComponent = entity->getComponent<SpriteComponent>();
        auto inputComponent = entity->getComponent<InputComponent>();

        if (transformComponent && inputComponent) {
            currentFrame = (int) (3 * time) % 3;
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

            if (inputComponent->keyPressed(sf::Keyboard::E) && !entity->getValue()) {
                entity->changeValue();
                inputComponent->updateKey(sf::Keyboard::E, false);
            } else if (inputComponent->keyPressed(sf::Keyboard::E) && entity->getValue()) {
                entity->changeValue();
                inputComponent->updateKey(sf::Keyboard::E, false);
            }
        }
    }
}