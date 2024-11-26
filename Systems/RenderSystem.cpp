#include <filesystem>
#include "RenderSystem.hpp"
#include "../Components/TransformComponent.hpp"
#include "../Components/SpriteComponent.hpp"
#include "../Components/CollisionComponent.hpp"
#include "../Components/DescriptionComponent.hpp"

void RenderSystem::setBackground(std::string fileName, sf::Vector2f position) {
    if (!backgroundTexture.loadFromFile(std::filesystem::current_path().string() + fileName)) {
        std::cerr << "Failed to load background image!" << std::endl;
    }

    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setPosition(position);
}

void RenderSystem::setDescription(std::string fileName) {
    if (!descriptionTexture.loadFromFile(std::filesystem::current_path().string() + fileName)) {
        std::cerr << "Failed to load background image!" << std::endl;
    }

    descriptionSprite.setTexture(descriptionTexture);
}


void RenderSystem::render(EntityManager& entityManager, sf::RenderWindow &window) {
    window.draw(backgroundSprite);

    for (auto &entity : entityManager.entities) {

        auto spriteComponent = entity->getComponent<SpriteComponent>();
        auto transformComponent = entity->getComponent<TransformComponent>();

        if (spriteComponent && transformComponent && IDManager::getIsRender(entity->ID)) {
            if (entity->flag == INVENTORY) {

                spriteComponent->getSprite().setPosition(transformComponent->getPosition());
                window.draw(spriteComponent->getSprite());

                for (auto &object : entityManager.inventory) {

                    auto spriteComponent1 = object->getComponent<SpriteComponent>();
                    auto transformComponent1 = object->getComponent<TransformComponent>();

                    spriteComponent1->getSprite().setPosition(transformComponent1->getPosition());
                    window.draw(spriteComponent1->getSprite());
                }

            } else {
                spriteComponent->getSprite().setPosition(transformComponent->getPosition());
                window.draw(spriteComponent->getSprite());
            }

            if (entity->flag == OBJECT && entity->getComponent<CollisionComponent>()->getCollision()) {
                auto descriptionComponent = entity->getComponent<DescriptionComponent>();
                descriptionSprite.setTextureRect(sf::IntRect(descriptionComponent->x, descriptionComponent->y,
                                                             descriptionComponent->width, descriptionComponent->height));
                descriptionSprite.setPosition(descriptionComponent->positionX, descriptionComponent->positionY);
                window.draw(descriptionSprite);
            }
        }
    }
}

void RenderSystem::update(EntityManager& entityManager, sf::Time& deltaTime) {

}
