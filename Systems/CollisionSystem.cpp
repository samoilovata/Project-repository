#include "CollisionSystem.hpp"

void CollisionSystem::update(EntityManager& entityManager, sf::Time &deltaTime) {
    for (size_t i = 0; i < entityManager.entities.size() - 1; i++) {
        auto entity1 = entityManager.entities[i];
        auto entity1TransformComponent = entity1->getComponent<TransformComponent>();
        auto entity1BoundsComponent = entity1->getComponent<BoundsComponent>();
        auto entity1CollisionComponent = entity1->getComponent<CollisionComponent>();
        auto entity1Position = entity1TransformComponent->getPosition();

        if (entity1TransformComponent && entity1BoundsComponent) {
            entity1BoundsComponent->setBounds(entity1Position);

            for (size_t j = i + 1; j < entityManager.entities.size(); j++) {
                auto entity2 = entityManager.entities[j];
                auto entity2TransformComponent = entity2->getComponent<TransformComponent>();
                auto entity2BoundsComponent = entity2->getComponent<BoundsComponent>();
                auto entity2CollisionComponent = entity2->getComponent<CollisionComponent>();
                auto entity2Position = entity2TransformComponent->getPosition();

                if (entity2TransformComponent && entity2BoundsComponent) {
                    entity2BoundsComponent->setBounds(entity2Position);

                    if (entity1CollisionComponent && entity2CollisionComponent && (entity1->location == 0 || entity1->location == entityManager.currentLocation)) {
                        if (entity1BoundsComponent->getBounds().intersects(entity2BoundsComponent->getBounds())) {
                            entity1CollisionComponent->collisionTrue();
                            entity2CollisionComponent->collisionTrue();
                        } else {
                            entity1CollisionComponent->collisionFalse();
                            entity2CollisionComponent->collisionFalse();
                        }
                    }
                }
            }
        }
    }
}
