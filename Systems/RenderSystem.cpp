#include "RenderSystem.hpp"
#include "../Components/TransformComponent.hpp"
#include "../Components/SpriteComponent.hpp"

void RenderSystem::render(sf::RenderWindow &window) {
    for (auto &entity : vectorEntity) {

        auto spriteComponent = entity->getComponent<SpriteComponent>();
        auto transformComponent = entity->getComponent<TransformComponent>();

        if (spriteComponent && transformComponent) {
            spriteComponent->getSprite().setPosition(transformComponent->getPosition());
            window.draw(spriteComponent->getSprite());
        }
    }
}

void RenderSystem::update(sf::Time& deltaTime) {

}