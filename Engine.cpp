#include <iostream>
#include <filesystem>
#include "Engine.hpp"
#include "SpawnEntity.hpp"

Engine::Engine() : window(sf::VideoMode(800, 640), "game") {
    renderSystem.setBackground("/../Assets/backgroundGrass.jpg", sf::Vector2f(-100, -100));

    player = std::make_shared<Entity>();
    coin = std::make_shared<Entity>();
    inventory = std::make_shared<Entity>();

    SpawnEntity (player, "/../Assets/spritePlayer.png", 100, 150, 200, 0, 190, 310);
    SpawnEntity(coin, "/../Assets/coin.png", 600, 500, 0, 0, 40, 40);
    SpawnEntityInventory(inventory, "/../Assets/inventory.png", 100, 100, 600, 300, 1000, 1000);

    renderSystem.addEntity(coin);
    renderSystem.addEntity(player);
    renderSystem.addEntity(inventory);

    inputSystem.addEntity(player);
    inputSystem.addEntity(inventory);

    collisionSystem.addEntity(player);
    collisionSystem.addEntity(coin);

}

void Engine::run() {
    const float timePerFrame = 1.0f / 60.0f;
    sf::Clock clock;
    sf::Time timeUpdate = sf::Time::Zero;

    while (window.isOpen()) {
        sf::Time deltaTime = clock.restart();
        timeUpdate += deltaTime;

        event();

        while (timeUpdate.asSeconds() > timePerFrame) {
            timeUpdate -= sf::seconds(timePerFrame);
            update(sf::seconds(timePerFrame));
        }

        render();
    }
}

void Engine::event() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
        else if (event.type == sf::Event::KeyPressed) {
            keyEvent(event.key.code, true);
        }
        else if (event.type == sf::Event::KeyReleased) {
            keyEvent(event.key.code, false);
        }
    }
}

void Engine::update(sf::Time deltaTime) {
    inputSystem.update(deltaTime);
    renderSystem.update(deltaTime);
    collisionSystem.update(deltaTime);
}

void Engine::keyEvent(sf::Keyboard::Key key, bool isPressed) {
    auto inputComponentPlayer = player->getComponent<InputComponent>();
    auto inputComponentInventory = inventory->getComponent<InputComponent>();
    if (inputComponentPlayer) inputComponentPlayer->updateKey(key, isPressed);
    if (inputComponentInventory) inputComponentInventory->updateKey(key, isPressed);
}

void Engine::render() {
    window.clear();
    renderSystem.render(window);
    window.display();
}
