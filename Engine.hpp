#pragma once
#include <SFML/Graphics.hpp>
#include "ECS/Entity.hpp"
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
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;

    std::shared_ptr<Entity> player;
    std::shared_ptr<Entity> coin;

    RenderSystem renderSystem;
    InputSystem inputSystem;
    CollisionSystem collisionSystem;

    void event();
    void update(sf::Time deltaTime);
    void keyEvent(sf::Keyboard::Key key, bool isPressed);
    void render();
};
