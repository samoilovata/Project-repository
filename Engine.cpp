#include <iostream>
#include <filesystem>
#include "Engine.hpp"
#include "SpawnEntity.hpp"

Engine::Engine() : window(sf::VideoMode(800, 640), "game") {
    renderSystem.setBackground("/../Assets/backgroundGrass.jpg", sf::Vector2f(-100, -100));

    std::shared_ptr<Entity> player = std::make_shared<Entity>();
    std::shared_ptr<Entity> coin = std::make_shared<Entity>();

    SpawnEntity (player, "/../Assets/spritePlayer.png", 100, 150, 200, 0, 190, 310);
    SpawnEntity(coin, "/../Assets/coin.png", 600, 500, 0, 0, 40, 40);
//    player = std::make_shared<Entity>();
//    auto transform = std::make_shared<TransformComponent>();
//    auto sprite = std::make_shared<SpriteComponent>(std::filesystem::current_path().string() + "/../Assets/spritePlayer.png", 200, 0, 190, 310);
//    auto bounds = std::make_shared<BoundsComponent>();
//    auto inputComponent = std::make_shared<InputComponent>();
//    transform->setPosition(200, 200);
//    bounds->setBounds(sprite->getSprite());
//
//    inputComponent->setKey(sf::Keyboard::W, false);
//    inputComponent->setKey(sf::Keyboard::S, false);
//    inputComponent->setKey(sf::Keyboard::A, false);
//    inputComponent->setKey(sf::Keyboard::D, false);
//    inputComponent->setKey(sf::Keyboard::F, false);
//
//    player->addComponent(transform);
//    player->addComponent(sprite);
//    player->addComponent(bounds);
//    player->addComponent(inputComponent);
//
//    coin = std::make_shared<Entity>();
//    auto coinTransform = std::make_shared<TransformComponent>();
//    auto coinSprite = std::make_shared<SpriteComponent>(std::filesystem::current_path().string() + "/../Assets/coin.png", 0, 0, 40, 40);
//    auto coinBounds = std::make_shared<BoundsComponent>();
//    coinTransform->setPosition(600, 500);
//    coinBounds->setBounds(coinSprite->getSprite());
//
//    coin->addComponent(coinTransform);
//    coin->addComponent(coinSprite);
//    coin->addComponent(coinBounds);

    renderSystem.addEntity(coin);
    renderSystem.addEntity(player);

    inputSystem.addEntity(player);

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
    auto inputComponent = player->getComponent<InputComponent>();
    if (inputComponent) inputComponent->setKey(key, isPressed);
}

void Engine::render() {
    window.clear();
    renderSystem.render(window);
    window.display();
}
