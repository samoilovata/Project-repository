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

void RenderSystem::render(std::vector<std::shared_ptr<Entity>>& entities, sf::RenderWindow &window) {
    window.draw(backgroundSprite);

    for (auto &entity : entities) {

        auto spriteComponent = entity->getComponent<SpriteComponent>();
        auto transformComponent = entity->getComponent<TransformComponent>();

        if (spriteComponent && transformComponent && entity->getValue()) {
            spriteComponent->getSprite().setPosition(transformComponent->getPosition());
            window.draw(spriteComponent->getSprite());
        }
    }
}

void RenderSystem::update(std::vector<std::shared_ptr<Entity>>& entities, sf::Time& deltaTime) {

}
