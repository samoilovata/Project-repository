#include "CollisionSystem.hpp"

void CollisionSystem::update(EntityManager& entityManager, sf::Time &deltaTime) {
    auto player = entityManager.playerPtr;
    auto playerTransformComponent = player->getComponent<TransformComponent>();
    auto playerBoundsComponent = player->getComponent<BoundsComponent>();
    auto playerCollisionComponent = player->getComponent<CollisionComponent>();
    auto playerPosition = playerTransformComponent->getPosition();

    if (playerTransformComponent && playerBoundsComponent) {
        playerBoundsComponent->setBounds(playerPosition);

        bool collisionFlag = false;

        for (const auto& entity : entityManager.entities) {
            if (entity == player) continue;

            auto entityTransformComponent = entity->getComponent<TransformComponent>();
            auto entityBoundsComponent = entity->getComponent<BoundsComponent>();
            auto entityCollisionComponent = entity->getComponent<CollisionComponent>();
            auto entityPosition = entityTransformComponent->getPosition();

            if (entityTransformComponent && entityBoundsComponent) {
                entityBoundsComponent->setBounds(entityPosition);

                if (playerCollisionComponent && entityCollisionComponent && (entity->location == entityManager.currentLocation || entity->location == 0)) {
                    if (playerBoundsComponent->getBounds().intersects(entityBoundsComponent->getBounds())) {
                        playerCollisionComponent->collisionTrue();
                        entityCollisionComponent->collisionTrue();
                        collisionFlag = true;
                    } else if (collisionFlag) {
                        entityCollisionComponent->collisionFalse();
                    } else {
                        playerCollisionComponent->collisionFalse();
                        entityCollisionComponent->collisionFalse();
                    }
                }
            }
        }
    }
}
