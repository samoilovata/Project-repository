#include <filesystem>
#include "RenderSystem.hpp"
#include "../Entities/ObjectEntity.hpp"
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
    if (entityManager.currentLocation == 1) {
        for (auto &entity : entityManager.entities) {
            if (entity->location == 0 || entity->location == entityManager.currentLocation) {
                auto spriteComponent = entity->getComponent<SpriteComponent>();
                auto transformComponent = entity->getComponent<TransformComponent>();

                if (spriteComponent && transformComponent && IDManager::getIsRender(entity->ID)) {
                    int iter = 0;
                    if (entity->flag == INVENTORY) {

                        spriteComponent->getSprite().setPosition(transformComponent->getPosition());
                        window.draw(spriteComponent->getSprite());

                        for (auto &object : entityManager.inventory) {

                            auto spriteComponent1 = object->getComponent<SpriteComponent>();
                            auto transformComponent1 = object->getComponent<TransformComponent>();

                            setPositionObjects(transformComponent1, iter);

                            spriteComponent1->getSprite().setPosition(transformComponent1->getPosition());
                            window.draw(spriteComponent1->getSprite());
                            iter++;
                        }

                    } else {
                        spriteComponent->getSprite().setPosition(transformComponent->getPosition());
                        window.draw(spriteComponent->getSprite());
                    }

                    if (entity->flag == OBJECT && entity->getComponent<CollisionComponent>()->getCollision()) {
                        auto descriptionComponent = entity->getComponent<DescriptionComponent>();
                        window.draw(descriptionComponent->description);
                    }
                }
            }
        }
    } else if (entityManager.currentLocation == 2) {
        window.clear(sf::Color::White);
        for (auto &entity : entityManager.entities) {
            if (entity->location == 0 || entity->location == entityManager.currentLocation) {
                auto spriteComponent = entity->getComponent<SpriteComponent>();
                auto transformComponent = entity->getComponent<TransformComponent>();

                if (spriteComponent && transformComponent && IDManager::getIsRender(entity->ID)) {
                    int iter = 0;
                    if (entity->flag == INVENTORY) {

                        spriteComponent->getSprite().setPosition(transformComponent->getPosition());
                        window.draw(spriteComponent->getSprite());

                        for (auto &object : entityManager.inventory) {

                            auto spriteComponent1 = object->getComponent<SpriteComponent>();
                            auto transformComponent1 = object->getComponent<TransformComponent>();

                            setPositionObjects(transformComponent1, iter);

                            spriteComponent1->getSprite().setPosition(transformComponent1->getPosition());
                            window.draw(spriteComponent1->getSprite());
                            iter++;
                        }

                    } else {
                        spriteComponent->getSprite().setPosition(transformComponent->getPosition());
                        window.draw(spriteComponent->getSprite());
                    }

                    if (entity->flag == OBJECT && entity->getComponent<CollisionComponent>()->getCollision()) {
                        auto descriptionComponent = entity->getComponent<DescriptionComponent>();
                        window.draw(descriptionComponent->description);
                    }
                }
            }
        }
    }
}

void RenderSystem::update(EntityManager& entityManager, sf::Time& deltaTime) {

}

void RenderSystem::setPositionObjects(std::shared_ptr<TransformComponent> transformComponent, int n) {
    if (n == 0) transformComponent->setPosition(60, 395);
    else transformComponent->setPosition(230 + 136 * ((n - 1) % 4), 192 + 150 * ((int) (n - 1) / 4));
}
