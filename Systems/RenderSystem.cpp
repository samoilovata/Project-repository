#include <filesystem>
#include "RenderSystem.hpp"

void RenderSystem::render(EntityManager& entityManager, sf::RenderWindow &window) {
    if (entityManager.endingState == 0) {
        window.draw(EntityManager::locationStatus[entityManager.currentLocation]->backgroundSprite);
        for (auto &entity: entityManager.entities) {
            if (entity->location == 0 || entity->location == entityManager.currentLocation) {
                auto spriteComponent = entity->getComponent<SpriteComponent>();
                auto transformComponent = entity->getComponent<TransformComponent>();

                if (transformComponent && IDManager::getIsRender(entity->ID)) {
                    if (spriteComponent) {
                        if (entity->flag == INVENTORY) {
                            int iter = 0;

                            spriteComponent->getSprite().setPosition(transformComponent->getPosition());
                            window.draw(spriteComponent->getSprite());

                            for (auto &object: entityManager.inventory) {

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
                    }

                    auto descriptionComponent = entity->getComponent<DescriptionComponent>();
                    if (descriptionComponent && entity->getComponent<CollisionComponent>()->getCollision()) {
                        window.draw(descriptionComponent->description);
                    }
                }
            }
        }
    } else {
        std::string fileName;

        if ((entityManager.endingState & ~42) == entityManager.endingState) fileName = "/../Assets/the_end1.png";
        else if ((entityManager.endingState & ~41) == entityManager.endingState) fileName = "/../Assets/the_end2.png";
        else if ((entityManager.endingState & ~26) == entityManager.endingState) fileName = "/../Assets/the_end3.png";
        else if ((entityManager.endingState & ~25) == entityManager.endingState) fileName = "/../Assets/the_end4.png";
        else if ((entityManager.endingState & ~38) == entityManager.endingState) fileName = "/../Assets/the_end5.png";
        else if ((entityManager.endingState & ~37) == entityManager.endingState) fileName = "/../Assets/the_end6.png";
        else if ((entityManager.endingState & ~22) == entityManager.endingState) fileName = "/../Assets/the_end7.png";
        else if ((entityManager.endingState & ~21) == entityManager.endingState) fileName = "/../Assets/the_end8.png";

        backgroundTextureEnding = std::make_shared<sf::Texture>();
        if (!backgroundTextureEnding->loadFromFile(std::filesystem::current_path().string() + fileName)) {
            std::cerr << "Failed to load background image!" << std::endl;
        }

        backgroundSpriteEnding.setTexture(*backgroundTextureEnding);
        backgroundSpriteEnding.setPosition(10, 10);
        backgroundSpriteEnding.setScale(5, 5);

        window.draw(backgroundSpriteEnding);
    }
}

void RenderSystem::setPositionObjects(const std::shared_ptr<TransformComponent>& transformComponent, int n) {
    if (n == 0) transformComponent->setPosition(70, 382);
    else transformComponent->setPosition(230 + 127 * ((n - 1) % 4), 180 + 142 * ((int) (n - 1) / 4));
}

void RenderSystem::update(EntityManager& entityManager, sf::Time& deltaTime) {

}
