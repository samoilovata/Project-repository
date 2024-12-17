#include <filesystem>
#include "Engine.hpp"

Engine::Engine() : window(sf::VideoMode(800, 640), "game") {
    renderSystem.setBackground("/../Assets/backgroundGrass.jpg", sf::Vector2f(-100, -100));
    renderSystem.setDescription("/../Assets/CoinScript.png");
    font.loadFromFile(std::filesystem::current_path().string() + "/../Assets/Font.ttf");

    player = std::make_shared<PlayerEntity>();
    inventory = std::make_shared<InventoryEntity>();
    coin = std::make_shared<ObjectEntity>();
    berry1 = std::make_shared<ObjectEntity>();
    berry2 = std::make_shared<ObjectEntity>();
    fish1 = std::make_shared<ObjectEntity>();
    fish2 = std::make_shared<ObjectEntity>();
    flower1 = std::make_shared<ObjectEntity>();
    flower2 = std::make_shared<ObjectEntity>();
    seeds = std::make_shared<ObjectEntity>();
    pound = std::make_shared<InteractiveObjectEntity>();

    entityManager.spawnPlayerEntity(player, "/../Assets/spritePlayer.png", 100, 100, 200, 0, 190, 310);
    entityManager.spawnInventoryEntity(inventory, "/../Assets/INVENTORY.png", 25, 125, 527, 1218, 7470, 5140);
    entityManager.spawnObjectEntity(coin, "/../Assets/coin.png", 600, 500, 129, 609, 40, 40, L"???????", font);
    entityManager.spawnObjectEntity(berry1, "/../Assets/sprite-berry1.png", 600, 200, 129, 1, 40, 40, "1234", font);
    entityManager.spawnObjectEntity(berry2, "/../Assets/sprite-berry2.png", 500, 200, 129, 1, 40, 40, "1234", font);
    entityManager.spawnObjectEntity(fish1, "/../Assets/sprite-fish1.png", 700, 500, 129, 0, 5, 100, "1234", font);
    entityManager.spawnObjectEntity(fish2, "/../Assets/sprite-fish2.png", 450, 150, 129, 1, 5, 100, "1234", font);
    entityManager.spawnObjectEntity(flower1, "/../Assets/sprite-flower1.png", 250, 200, 126, 0, 40, 40, "1234", font);
    entityManager.spawnObjectEntity(flower2, "/../Assets/sprite-flower2.png", 300, 150, 126, 0, 40, 40, "1234", font);
    entityManager.spawnObjectEntity(seeds, "/../Assets/sprite-seeds.png", 50, 150, 126, 0, 40, 40, "1234", font);
    entityManager.spawnInteractiveObjectEntity(pound, "/../Assets/pound.png", 100, 450, 0, 0, 160, 160, "5678", font);


    IDManager::changeIsCoin(coin->ID);
    IDManager::changeIsCoin(pound->ID);

    entityManager.entities.push_back(coin);
    entityManager.entities.push_back(berry1);
    entityManager.entities.push_back(berry2);
    entityManager.entities.push_back(fish1);
    entityManager.entities.push_back(fish2);
    entityManager.entities.push_back(flower1);
    entityManager.entities.push_back(flower2);
    entityManager.entities.push_back(seeds);
    entityManager.entities.push_back(pound);
    entityManager.entities.push_back(player);
    entityManager.entities.push_back(inventory);
}

void Engine::run() {
    const float timePerFrame = 1.0f / 60.0f;
    sf::Clock clock;
    sf::Time timeUpdate = sf::Time::Zero;

    while (window.isOpen()) {
        sf::Time deltaTime = clock.restart();
        timeUpdate += deltaTime;

        while (timeUpdate.asSeconds() > timePerFrame) {
            timeUpdate -= sf::seconds(timePerFrame);
            update(sf::seconds(timePerFrame));
        }

        render();
    }
}

void Engine::update(sf::Time deltaTime) {
    inputSystem.update(window);
    interactionSystem.update(entityManager, deltaTime);
    moveSystem.update(entityManager, deltaTime);
    renderSystem.update(entityManager, deltaTime);
    collisionSystem.update(entityManager, deltaTime);
    inventorySystem.update(entityManager, deltaTime);
}

void Engine::render() {
    window.clear();
    renderSystem.render(entityManager, window);
    window.display();
}
