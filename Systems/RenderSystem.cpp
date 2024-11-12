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

void RenderSystem::render(std::vector<std::shared_ptr<Entity>> &objects, std::vector<std::shared_ptr<Entity>>& entities, sf::RenderWindow &window) {
    window.draw(backgroundSprite);

    for (auto &entity : entities) {

        auto spriteComponent = entity->getComponent<SpriteComponent>();
        auto transformComponent = entity->getComponent<TransformComponent>();

        if (spriteComponent && transformComponent && IDManager::getIsRender(entity->ID)) {
            if (entity->flag == INVENTORY) {

                spriteComponent->getSprite().setPosition(transformComponent->getPosition());
                window.draw(spriteComponent->getSprite());

                for (auto &object : objects) {

                    auto spriteComponent1 = object->getComponent<SpriteComponent>();
                    auto transformComponent1 = object->getComponent<TransformComponent>();

                    spriteComponent1->getSprite().setPosition(transformComponent1->getPosition());
                    window.draw(spriteComponent1->getSprite());
                }

            } else {

                spriteComponent->getSprite().setPosition(transformComponent->getPosition());
                window.draw(spriteComponent->getSprite());

            }
        }
    }
}

void RenderSystem::update(std::vector<std::shared_ptr<Entity>> &objects, std::vector<std::shared_ptr<Entity>>& entities, sf::Time& deltaTime) {

}
