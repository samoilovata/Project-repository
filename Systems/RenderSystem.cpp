#include <filesystem>
#include "RenderSystem.hpp"
#include "../Components/TransformComponent.hpp"
#include "../Components/SpriteComponent.hpp"

void RenderSystem::setBackground(std::string fileName, sf::Vector2f position) {
    if (!backgroundTexture.loadFromFile(std::filesystem::current_path().string() + fileName)) {
        std::cerr << "Failed to load background image!" << std::endl;
    }

    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setPosition(position);
}

void RenderSystem::render(sf::RenderWindow &window) {
    window.draw(backgroundSprite);

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
