#pragma once
#include <SFML/Graphics.hpp>
#include "ECS/Entity.hpp"
#include "Entities/PlayerEntity.hpp"
#include "Entities/InventoryEntity.hpp"
#include "Entities/ObjectEntity.hpp"
#include "Systems/RenderSystem.hpp"
#include "Systems/InputSystem.hpp"
#include "Systems/CollisionSystem.hpp"
#include "Components/SpriteComponent.hpp"
#include "Components/TransformComponent.hpp"

class Engine {
public:
    Engine();
    void run();

private:
    sf::RenderWindow window;

    std::shared_ptr<PlayerEntity> player;
    std::shared_ptr<InventoryEntity> inventory;
    std::shared_ptr<ObjectEntity> coin;

    RenderSystem renderSystem;
    InputSystem inputSystem;
    CollisionSystem collisionSystem;

    void event();
    void update(float time, sf::Time deltaTime);
    void keyEvent(sf::Keyboard::Key key, bool isPressed);
    void render();
};
