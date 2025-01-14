#include <cmath>
#include "ScriptSystem.hpp"
#include "../IDManager.hpp"

void ScriptSystem::update(EntityManager &entityManager, sf::Time &deltaTime) {
    if (entityManager.scriptStatus & (1 << 2)) scriptFlower(entityManager, deltaTime);
    else if (entityManager.scriptStatus & 1) scriptFish(entityManager, deltaTime, false);
    else if (entityManager.scriptStatus & (1 << 1)) scriptFish(entityManager, deltaTime, true);
    else if (entityManager.scriptStatus & (1 << 3)) scriptPot(entityManager, deltaTime);
}

void ScriptSystem::scriptFish(EntityManager &entityManager, sf::Time &deltaTime, bool fishType) {
    std::shared_ptr<Entity> fish;

    if (!fishType) {
        for (auto const& entity : entityManager.entities) {
            if (entity->flag != OBJECT) continue;

            if (IDManager::getIsFish1(entity->ID)) {
                fish = entity;
                break;
            }
        }
    } else {
        for (auto const& entity : entityManager.entities) {
            if (entity->flag != OBJECT) continue;

            if (IDManager::getIsFish2(entity->ID)) {
                fish = entity;
                break;
            }
        }
    }

    if (!IDManager::getIsRender(fish->ID)) IDManager::changeIsRender(fish->ID);
    time += deltaTime;

    if (time.asSeconds() < 1.5) {
        auto transformComponent = fish->getComponent<TransformComponent>();
        auto descriptionComponent = fish->getComponent<DescriptionComponent>();

        transformComponent->setPosition(transformComponent->getPosition().x + 1, -50 * std::sin(transformComponent->getPosition().x * 0.045) + 600);
        descriptionComponent->setPosition(transformComponent->getPosition(), fish->getComponent<SpriteComponent>()->getSprite().getScale().x);
    } else {
        time = sf::Time::Zero;
        entityManager.scriptStatus = entityManager.scriptStatus & ~3;
    }
}

void ScriptSystem::scriptFlower(EntityManager &entityManager, sf::Time &deltaTime) {
    std::shared_ptr<Entity> gardenbed;
    std::shared_ptr<Entity> flower;

    for (auto const& entity : entityManager.entities) {
        if (entity->flag != INTERACTIVE_OBJECT) continue;

        if (IDManager::getIsSeeds(entity->ID)) {
            gardenbed = entity;
            break;
        }
    }
    for (auto const& entity : entityManager.entities) {
        if (entity->flag != OBJECT) continue;

        if (IDManager::getIsFlower2(entity->ID)) {
            flower = entity;
            break;
        }
    }

    time += deltaTime;

    auto spriteComponent = gardenbed->getComponent<SpriteComponent>();

    if (time.asSeconds() < 5) {
        spriteComponent->getSprite().setTextureRect(sf::IntRect(58, 1, 57, 28));
    } else if (time.asSeconds() < 10) {
        spriteComponent->getSprite().setTextureRect(sf::IntRect(116, 1, 57, 28));
    } else {
        time = sf::Time::Zero;
        entityManager.scriptStatus = entityManager.scriptStatus & ~4;

        spriteComponent->getSprite().setTextureRect(sf::IntRect(58, 1, 57, 28));
        IDManager::changeIsRender(flower->ID);
    }
}

void ScriptSystem::scriptPot(EntityManager &entityManager, sf::Time &deltaTime) {
    std::shared_ptr<Entity> pot;

    for (auto const& entity : entityManager.entities) {
        if (entity->flag != INTERACTIVE_OBJECT) continue;

        if (IDManager::getIsPot(entity->ID)) {
            pot = entity;
            break;
        }
    }

    time += deltaTime;

    if (time.asSeconds() < 5) {
        pot->getComponent<DescriptionComponent>()->setText(L"Кажется, вот-вот\n что-то произойдет");
    } else if (time.asSeconds() < 10) {
        pot->getComponent<DescriptionComponent>()->setText(L"Ого!");
        pot->getComponent<SpriteComponent>()->getSprite().setTextureRect(sf::IntRect(45, 1, 21, 28));
    } else {
        time = sf::Time::Zero;
//        entityManager.scriptStatus = entityManager.scriptStatus & ~8;
    }
}
