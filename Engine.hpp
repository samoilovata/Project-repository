#pragma once
#include <SFML/Graphics.hpp>
#include "EntityManager.hpp"
#include "ECS/Entity.hpp"
#include "Entities/PlayerEntity.hpp"
#include "Entities/InventoryEntity.hpp"
#include "Entities/ObjectEntity.hpp"
#include "Entities/LocationObjectEntity.hpp"
#include "Entities/StaticObjectEntity.hpp"
#include "Systems/InventorySystem.hpp"
#include "Systems/RenderSystem.hpp"
#include "Systems/InputSystem.hpp"
#include "Systems/CollisionSystem.hpp"
#include "Systems/InteractionSystem.hpp"
#include "Systems/MoveSystem.hpp"
#include "Systems/ScriptSystem.hpp"
#include "Components/SpriteComponent.hpp"
#include "Components/TransformComponent.hpp"

class Engine {
public:
    Engine();
    void run();

private:
    sf::RenderWindow window;
    sf::Font font;

    EntityManager entityManager;

    std::shared_ptr<PlayerEntity> player;
    std::shared_ptr<InventoryEntity> inventory;

    std::shared_ptr<ObjectEntity> coin;
    std::shared_ptr<ObjectEntity> berry1;
    std::shared_ptr<ObjectEntity> berry2;
    std::shared_ptr<ObjectEntity> fish1;
    std::shared_ptr<ObjectEntity> fish2;
    std::shared_ptr<ObjectEntity> flower1;
    std::shared_ptr<ObjectEntity> flower2;
    std::shared_ptr<ObjectEntity> seeds;

    std::shared_ptr<StaticObjectEntity> bush;
    std::shared_ptr<StaticObjectEntity> house;
    std::shared_ptr<StaticObjectEntity> staticPond;
    std::shared_ptr<StaticObjectEntity> armchair;
    std::shared_ptr<StaticObjectEntity> bed;
    std::shared_ptr<StaticObjectEntity> closet;
    std::shared_ptr<StaticObjectEntity> table;
    std::shared_ptr<StaticObjectEntity> tree;
    std::shared_ptr<StaticObjectEntity> flowerbed;

    std::shared_ptr<LocationObjectEntity> doorInside;
    std::shared_ptr<LocationObjectEntity> doorOutside;

    std::shared_ptr<InteractiveObjectEntity> pond;
    std::shared_ptr<InteractiveObjectEntity> gardenbed;
    std::shared_ptr<InteractiveObjectEntity> pot;

    InventorySystem inventorySystem;
    RenderSystem renderSystem;
    InputSystem inputSystem;
    CollisionSystem collisionSystem;
    MoveSystem moveSystem;
    InteractionSystem interactionSystem;
    ScriptSystem scriptSystem;

    void update(sf::Time deltaTime);
    void render();
};
