#include <filesystem>
#include "Engine.hpp"

Engine::Engine() : window(sf::VideoMode(800, 640), "game") {
    font.loadFromFile(std::filesystem::current_path().string() + "/../Assets/Font.ttf");

    entityManager.spawnLocation("/../Assets/background_grass.png", sf::Vector2f(-100, -100), sf::Vector2f(100, 100), 1);
    entityManager.spawnLocation("/../Assets/background_grass.png", sf::Vector2f(0, 0), sf::Vector2f(200, 200), 2);

    player = std::make_shared<PlayerEntity>();
    inventory = std::make_shared<InventoryEntity>();
    coin = std::make_shared<ObjectEntity>();
    coin2 = std::make_shared<LocationObjectEntity>();
    berry1 = std::make_shared<ObjectEntity>();
    berry2 = std::make_shared<ObjectEntity>();
    fish1 = std::make_shared<ObjectEntity>();
    fish2 = std::make_shared<ObjectEntity>();
    flower1 = std::make_shared<ObjectEntity>();
    flower2 = std::make_shared<ObjectEntity>();
    seeds = std::make_shared<ObjectEntity>();
    pound = std::make_shared<InteractiveObjectEntity>();

    entityManager.spawnPlayerEntity(player, "/../Assets/sprite-player.png", 100, 100, 200, 0, 190, 310);
    entityManager.spawnInventoryEntity(inventory, "/../Assets/sprite-inventory.png", 0, 0, 0, 0, 800, 640);

    entityManager.spawnObjectEntity(coin, "/../Assets/sprite-coin.png", 600, 500, 128, 0, 7, 9, L"Монетка", font, 2);
    entityManager.spawnObjectEntity(berry1, "/../Assets/sprite-berry1.png", 600, 200, 128, 0, 7, 9, L"Ягода", font, 1);
    entityManager.spawnObjectEntity(berry2, "/../Assets/sprite-berry2.png", 500, 200, 128, 0, 7, 9, L"Немного гнилая\nягода", font, 1);
    entityManager.spawnObjectEntity(fish1, "/../Assets/sprite-fish1.png", 700, 500, 128, 0, 7, 9, L"Золотая рыбка", font, 1);
    entityManager.spawnObjectEntity(fish2, "/../Assets/sprite-fish2.png", 450, 150, 128, 0, 7, 9, L"Селедка", font, 1);
    entityManager.spawnObjectEntity(flower1, "/../Assets/sprite-flower1.png", 250, 200, 128, 0, 7, 9, L"Тюльпан", font, 1);
    entityManager.spawnObjectEntity(flower2, "/../Assets/sprite-flower2.png", 300, 150, 128, 0, 7, 9, L"Оч красиви\nцветочек", font, 1);
    entityManager.spawnObjectEntity(seeds, "/../Assets/sprite-seeds.png", 50, 150, 128, 0, 7, 9, L"Семена", font, 1);
    entityManager.spawnLocationObjectEntity(coin2, "/../Assets/sprite-coin.png", 300, 200, 128, 0, 7, 9, L"Телепорт", font, 0);
    entityManager.spawnInteractiveObjectEntity(pound, "/../Assets/pound.png", 100, 450, 0, 0, 160, 160, L"Пруд", font, 1);


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
    entityManager.entities.push_back(coin2);
    entityManager.entities.push_back(player);
    entityManager.entities.push_back(inventory);

    entityManager.playerPtr = player;
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
