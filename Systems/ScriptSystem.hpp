#pragma once
#include "../ECS/System.hpp"
#include "../EntityManager.hpp"

class ScriptSystem : public System {
public:
    void update(EntityManager& entityManager, sf::Time& deltaTime) override;

    void scriptFish(EntityManager &entityManager, sf::Time &deltaTime, bool fishType);
    void scriptFlower(EntityManager &entityManager, sf::Time &deltaTime);
    void scriptPot(EntityManager &entityManager, sf::Time &deltaTime);

    sf::Time time;
};
