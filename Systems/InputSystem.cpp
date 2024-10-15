#include "InputSystem.hpp"
#include "../Components/TransformComponent.hpp"
#include "../Components/SpriteComponent.hpp"
#include "../Components/InputComponent.hpp"
#include <SFML/Window/Keyboard.hpp>

void InputSystem::update(sf::Time& deltaTime) {
    for (auto &entity : vectorEntity) {
        auto transformComponent = entity->getComponent<TransformComponent>();
        auto spriteComponent = entity->getComponent<SpriteComponent>();
        auto inputComponent = entity->getComponent<InputComponent>();

        if (transformComponent && inputComponent) {
            float currentFrame;

            if (inputComponent->keyPressed(sf::Keyboard::W)) {
                currentFrame = (int) (4 * deltaTime.asSeconds()) % 4;
                if (currentFrame == 3) currentFrame -= 2;
                spriteComponent->getSprite().setTextureRect(sf::IntRect (int(currentFrame) * 200, 330, 200, 320));
                spriteComponent->getSprite().move(0, -0.0005 * deltaTime.asMicroseconds());
            }

            if (inputComponent->keyPressed(sf::Keyboard::S)) {
                currentFrame = (int) (4 * deltaTime.asSeconds()) % 4;
                if (currentFrame == 3) currentFrame -= 2;
                spriteComponent->getSprite().setTextureRect(sf::IntRect (int(currentFrame) * 200, 0, 200, 320));
                spriteComponent->getSprite().move(0, 0.0005 * deltaTime.asMicroseconds());
            }

            if (inputComponent->keyPressed(sf::Keyboard::A)) {
                currentFrame = (int) (4 * deltaTime.asSeconds()) % 4;
                if (currentFrame == 3) currentFrame -= 2;
                spriteComponent->getSprite().setTextureRect(sf::IntRect (int(currentFrame) * 200, 980, 200, 320));
                spriteComponent->getSprite().move(-0.0005 * deltaTime.asMicroseconds(), 0);
            }

            if (inputComponent->keyPressed(sf::Keyboard::D)) {
                currentFrame = (int) (4 * deltaTime.asSeconds()) % 4;
                if (currentFrame == 3) currentFrame -= 2;
                spriteComponent->getSprite().setTextureRect(sf::IntRect (int(currentFrame) * 200, 660, 200, 320));
                spriteComponent->getSprite().move(0.0005 * deltaTime.asMicroseconds(), 0);
            }
        }
    }
}