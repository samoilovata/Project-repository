
#include "Engine.hpp"

int main() {
    Engine game;
    game.run();

    return 0;
//    sf::RenderWindow window(sf::VideoMode(800, 640), "game");
//    sf::Texture backgroundTexture;
//
//    if (!backgroundTexture.loadFromFile(std::filesystem::current_path().string() + "/../Assets/backgroundGrass.jpg")) {
//        std::cerr << "Failed to load background image!" << std::endl;
//    }
//
//    sf::Sprite backgroundGrass;
//    backgroundGrass.setTexture(backgroundTexture);
//
//    backgroundGrass.setPosition(sf::Vector2f(-100, -100));
//
//    tempObject coin("");
//    Player P1("");
//    sf::Clock clock;
//    sf::Time elapsedTime;
//
//    while (window.isOpen()) {
//
//        sf::Time deltaTime = clock.restart();
//        elapsedTime += deltaTime;
//        float time = elapsedTime.asSeconds();
//
//        sf::Event event{};
//        while (window.pollEvent(event))
//        {
//            if (event.type == sf::Event::Closed)
//                window.close();
//        }
//
//        window.clear();
//
//        window.draw(backgroundGrass);
//        window.draw(coin.getSprite());
//        window.draw(P1.getSprite());
//        P1.movePlayer(time, deltaTime);
//        P1.setBounds();
//
//        if (P1.getBounds().intersects(coin.getBounds())) {
//            if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
//                coin.setPosition(std::rand() % (700 - 100 + 1) + 100, std::rand() % (540 - 100 + 1) + 100);
//            }
//        }
//
//        window.display();
//    }
}
