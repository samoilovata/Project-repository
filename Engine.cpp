#include <filesystem>
#include "Engine.hpp"

Engine::Engine() : window(sf::VideoMode(800, 640), "game") {
    renderSystem.setBackground("/../Assets/backgroundGrass.jpg", sf::Vector2f(-100, -100));
    renderSystem.setDescription("/../Assets/Script.png");

    player = std::make_shared<PlayerEntity>();
    inventory = std::make_shared<InventoryEntity>();
    coin = std::make_shared<ObjectEntity>();

    entityManager.spawnPlayerEntity(player, "/../Assets/spritePlayer.png", 100, 150, 200, 0, 190, 310);
    entityManager.spawnInventoryEntity(inventory, "/../Assets/INVENTORY.png", 25, 75, 527, 1218, 7470, 5140);
    entityManager.spawnObjectEntity(coin, "/../Assets/coin.png", 600, 500, 0, 0, 40, 40, 200, 200, 500, 300);

    entity_id.insert({player->ID, player});
    entity_id.insert({inventory->ID, inventory});
    entity_id.insert({coin->ID, coin});

    entities.push_back(coin);
    entities.push_back(player);
    entities.push_back(inventory);
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
    inputSystem.update(entities, deltaTime);
    renderSystem.update(entities, deltaTime);
    collisionSystem.update(entities, deltaTime);
    inventorySystem.update(entities, deltaTime);
}

void Engine::keyEvent(sf::Keyboard::Key key, bool isPressed) {
    auto inputComponentPlayer = player->getComponent<InputComponent>();
    auto inputComponentInventory = inventory->getComponent<InputComponent>();
    if (inputComponentPlayer) inputComponentPlayer->updateKey(key, isPressed);
    if (inputComponentInventory) inputComponentInventory->updateKey(key, isPressed);
}

void Engine::render() {
    window.clear();
    renderSystem.render(entities,window);
    window.display();
}
