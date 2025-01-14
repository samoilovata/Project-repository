#include <filesystem>
#include "Engine.hpp"

Engine::Engine() : window(sf::VideoMode(800, 640), "Tiny story") {
    font.loadFromFile(std::filesystem::current_path().string() + "/../Assets/Font.ttf");

    entityManager.spawnLocation("/../Assets/background-grass.png", sf::Vector2f(-100, -100), sf::Vector2f(480, 230), 1);
    entityManager.spawnLocation("/../Assets/background-room.png", sf::Vector2f(10, 10), sf::Vector2f(350, 490), 2);

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

    bush = std::make_shared<StaticObjectEntity>();
    house = std::make_shared<StaticObjectEntity>();
    staticPond = std::make_shared<StaticObjectEntity>();
    armchair = std::make_shared<StaticObjectEntity>();
    bed = std::make_shared<StaticObjectEntity>();
    closet = std::make_shared<StaticObjectEntity>();
    table = std::make_shared<StaticObjectEntity>();
    tree = std::make_shared<StaticObjectEntity>();
    flowerbed = std::make_shared<StaticObjectEntity>();

    doorInside = std::make_shared<LocationObjectEntity>();
    doorOutside = std::make_shared<LocationObjectEntity>();

    pond = std::make_shared<InteractiveObjectEntity>();
    gardenbed = std::make_shared<InteractiveObjectEntity>();
    pot = std::make_shared<InteractiveObjectEntity>();

    wall1 = std::make_shared<EmptyObjectEntity>();
    wall2 = std::make_shared<EmptyObjectEntity>();
    wall3 = std::make_shared<EmptyObjectEntity>();

    entityManager.spawnPlayerEntity(player, "/../Assets/sprite-player.png", 500, 300, 20, 1, 19, 30);
    entityManager.spawnInventoryEntity(inventory, "/../Assets/sprite-inventory.png", 0, 0, 0, 0, 800, 640);

    entityManager.spawnObjectEntity(coin, "/../Assets/sprite-coin.png", 195, 245, 128, 0, 4, 5, L"Монетка. Такие кидают\nв пруд на удачу.\nСтоит ли её оставить себе?", font, 2);
    entityManager.spawnObjectEntity(berry1, "/../Assets/sprite-berry1.png", 130, 160, 128, 0, 4, 6, L"Спелая ягода.\nВыглядит вкусно", font, 1);
    entityManager.spawnObjectEntity(berry2, "/../Assets/sprite-berry2.png", 570, 540, 128, 0, 4, 5, L"Немного гнилая\nягода", font, 2);
    entityManager.spawnObjectEntity(fish1, "/../Assets/sprite-fish1.png", 250, 600, 128, 0, 7, 7, L"Золотая рыбка", font, 1);
    entityManager.spawnObjectEntity(fish2, "/../Assets/sprite-fish2.png", 250, 600, 128, 0, 7, 5, L"Селедка", font, 1);
    entityManager.spawnObjectEntity(flower1, "/../Assets/sprite-flower1.png", 690, 240, 128, 0, 6, 9, L"Кто-то\nпосадил\nего здесь.\nВы точно\nхотите его\nсорвать?", font, 1);
    entityManager.spawnObjectEntity(flower2, "/../Assets/sprite-flower2.png", 625, 505, 128, 0, 5, 10, L"Красивый цветочек", font, 1);
    entityManager.spawnObjectEntity(seeds, "/../Assets/sprite-seeds.png", 405, 255, 128, 0, 7, 7, L"Семена цветов.\nИнтересно, каких?", font, 2);

    entityManager.spawnStaticObjectEntity(bush, "/../Assets/sprite-bush.png", -100, 0, 0, 0, 105, 53, 1);
    entityManager.spawnStaticObjectEntity(house, "/../Assets/house.png", 160, -400, 13, 0, 215, 145, 1);
    entityManager.spawnStaticObjectEntity(staticPond, "/../Assets/pond.png", 275, 525, 185, 15, 15, 35, 1);
    entityManager.spawnStaticObjectEntity(armchair, "/../Assets/armchair.png", 595, 175, 0, 0, 32, 30, 2);
    entityManager.spawnStaticObjectEntity(bed, "/../Assets/bed.png", 625, 350, 0, 0, 29, 46, 2);
    entityManager.spawnStaticObjectEntity(closet, "/../Assets/closet.png", 295, 40, 0, 0, 58, 54, 2);
    entityManager.spawnStaticObjectEntity(table, "/../Assets/table.png", 35, 180, 0, 0, 53, 33, 2);
    entityManager.spawnStaticObjectEntity(tree, "/../Assets/tree.png", 55, 395, 0, 0, 23, 33, 2);
    entityManager.spawnStaticObjectEntity(flowerbed, "/../Assets/flowerbed.png", 610, 260, 0, 0, 38, 18, 1);

    entityManager.spawnLocationObjectEntity(doorInside, 475, 190, 100, 50, L"Войти", font, 1);
    entityManager.spawnLocationObjectEntity(doorOutside, 350, 630, 100, 50, L"Выйти", font, 2);

    entityManager.spawnInteractiveObjectEntity(pond, "/../Assets/pond.png", 0, 450, 130, 0, 55, 50, L"В пруду плавает\nрыбка. Вы можете\nеё поймать!", font, 1);
    entityManager.spawnInteractiveObjectEntity(gardenbed, "/../Assets/gardenbed.png", 500, 500, 0, 1, 57, 28, L"Кажется, здесь можно\nчто-то вырастить", font, 1);
    entityManager.spawnInteractiveObjectEntity(pot, "/../Assets/pot.png", 165, 420, 0, 1, 21, 28, L"Нужно собрать\nвсе ингредиенты", font, 2);

    entityManager.spawnEmptyObjectEntity(wall1, 125, 570, 200, 50, 2);
    entityManager.spawnEmptyObjectEntity(wall2, 470, 570, 200, 50, 2);
    entityManager.spawnEmptyObjectEntity(wall3, 0, 0, 40, 640, 2);


    IDManager::changeIsCoin(coin->ID);
    IDManager::changeIsCoin(pond->ID);
    IDManager::changeIsBerry1(berry1->ID);
    IDManager::changeIsBerry1(pot->ID);
    IDManager::changeIsBerry2(berry2->ID);
    IDManager::changeIsBerry2(pot->ID);
    IDManager::changeIsFlower1(flower1->ID);
    IDManager::changeIsFlower1(pot->ID);
    IDManager::changeIsFlower2(flower2->ID);
    IDManager::changeIsFlower2(pot->ID);
    IDManager::changeIsFish1(fish1->ID);
    IDManager::changeIsFish1(pot->ID);
    IDManager::changeIsFish2(fish2->ID);
    IDManager::changeIsFish2(pot->ID);
    IDManager::changeIsSeeds(seeds->ID);
    IDManager::changeIsSeeds(gardenbed->ID);
    IDManager::changeIsPot(pot->ID);

    IDManager::changeIsRender(fish1->ID);
    IDManager::changeIsRender(fish2->ID);
    IDManager::changeIsRender(flower2->ID);

    entityManager.entities.push_back(bush);
    entityManager.entities.push_back(house);
    entityManager.entities.push_back(staticPond);
    entityManager.entities.push_back(armchair);
    entityManager.entities.push_back(closet);
    entityManager.entities.push_back(bed);
    entityManager.entities.push_back(table);
    entityManager.entities.push_back(tree);
    entityManager.entities.push_back(flowerbed);

    entityManager.entities.push_back(pond);
    entityManager.entities.push_back(gardenbed);
    entityManager.entities.push_back(pot);

    entityManager.entities.push_back(coin);
    entityManager.entities.push_back(berry1);
    entityManager.entities.push_back(berry2);
    entityManager.entities.push_back(fish1);
    entityManager.entities.push_back(fish2);
    entityManager.entities.push_back(flower1);
    entityManager.entities.push_back(flower2);
    entityManager.entities.push_back(seeds);

    entityManager.entities.push_back(doorInside);
    entityManager.entities.push_back(doorOutside);
    entityManager.entities.push_back(player);
    entityManager.entities.push_back(inventory);

    entityManager.entities.push_back(wall1);
    entityManager.entities.push_back(wall2);
    entityManager.entities.push_back(wall3);

    entityManager.playerPtr = player;
}

void Engine::play() {
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
    collisionSystem.update(entityManager, deltaTime);
    interactionSystem.update(entityManager, deltaTime);
    scriptSystem.update(entityManager, deltaTime);
    moveSystem.update(entityManager, deltaTime);
    inventorySystem.update(entityManager, deltaTime);
}

void Engine::render() {
    window.clear();
    renderSystem.render(entityManager, window);
    window.display();
}

void Engine::run() {
    sf::Sprite backgroundSprite;
    auto backgroundTexture = std::make_shared<sf::Texture>();

    if (!backgroundTexture->loadFromFile(std::filesystem::current_path().string() + "/../Assets/menu.png")) {
        std::cerr << "Failed to load background image!" << std::endl;
    }

    backgroundSprite.setTexture(*backgroundTexture);

    GameMenu gameMenu;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::KeyReleased) {
                if (event.key.code == sf::Keyboard::Up) gameMenu.MoveUp();
                if (event.key.code == sf::Keyboard::Down) gameMenu.MoveDown();
                if (event.key.code == sf::Keyboard::Return) {
                    switch (gameMenu.getSelectedMenuNumber()) {
                        case 0:play();   break;
                        case 1:window.close(); break;
                    }
                }
            }
        }

        window.clear();
        window.draw(backgroundSprite);
        gameMenu.draw(window);
        window.display();
    }
}
