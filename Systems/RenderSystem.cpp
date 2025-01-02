#include <filesystem>
#include "RenderSystem.hpp"
#include "../Entities/ObjectEntity.hpp"
#include "../Components/TransformComponent.hpp"
#include "../Components/SpriteComponent.hpp"
#include "../Components/CollisionComponent.hpp"
#include "../Components/DescriptionComponent.hpp"

void RenderSystem::render(EntityManager& entityManager, sf::RenderWindow &window) {
    window.draw(EntityManager::locationStatus[entityManager.currentLocation]->backgroundSprite);
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

                auto descriptionComponent = entity->getComponent<DescriptionComponent>();
                if (descriptionComponent && entity->getComponent<CollisionComponent>()->getCollision()) {
                    window.draw(descriptionComponent->description);
                }
            }
        }
    }
}

void RenderSystem::setPositionObjects(const std::shared_ptr<TransformComponent>& transformComponent, int n) {
    if (n == 0) transformComponent->setPosition(70, 382);
    else transformComponent->setPosition(230 + 127 * ((n - 1) % 4), 185 + 142 * ((int) (n - 1) / 4));
}

void RenderSystem::update(EntityManager& entityManager, sf::Time& deltaTime) {

}
