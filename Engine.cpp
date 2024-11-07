#include <filesystem>
#include "Engine.hpp"

Engine::Engine() : window(sf::VideoMode(800, 640), "game") {
    renderSystem.setBackground("/../Assets/backgroundGrass.jpg", sf::Vector2f(-100, -100));

    player = std::make_shared<PlayerEntity>();
    inventory = std::make_shared<InventoryEntity>();
    coin = std::make_shared<ObjectEntity>();

    player->spawnPlayerEntity("/../Assets/spritePlayer.png", 100, 150, 200, 0, 190, 310);
    inventory->spawnInventoryEntity("/../Assets/inventory.png", 25, 75, 527, 1218, 7470, 5140);
    coin->spawnObjectEntity("/../Assets/coin.png", 600, 500, 0, 0, 40, 40);

    entity_id.insert({player->getID(), player});
    entity_id.insert({inventory->getID(), inventory});
    entity_id.insert({coin->getID(), coin});

    entities.push_back(coin);
    entities.push_back(player);
    entities.push_back(inventory);
}

void Engine::run() {
    sf::Clock clock;
    sf::Time elapsedTime;

    while (window.isOpen()) {

        sf::Time deltaTime = clock.restart();
        elapsedTime += deltaTime;
        float time = elapsedTime.asSeconds();

        event();

        if (elapsedTime > sf::milliseconds(20)) {
            update(time, deltaTime);
            elapsedTime = sf::milliseconds(0);
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

void Engine::update(float time, sf::Time deltaTime) {
    inputSystem.update(time,entities, deltaTime);
    renderSystem.update(time, entities, deltaTime);
    collisionSystem.update(time,entities, deltaTime);
    inventorySystem.update(time, entities, deltaTime);
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
