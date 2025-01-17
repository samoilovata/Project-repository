#include <filesystem>
#include "GameMenu.hpp"

GameMenu::GameMenu() {
    buttonPlay = std::make_shared<Button>();
    buttonExit = std::make_shared<Button>();

    buttonPlay->sprite = std::make_shared<SpriteComponent>("./Assets/play.png",
                                                           0, 0, 532, 258);
    buttonPlay->sprite->getSprite().setScale(1, 1);
    buttonPlay->transform = std::make_shared<TransformComponent>();
    buttonPlay->transform->setPosition(135, 20);

    buttonExit->sprite = std::make_shared<SpriteComponent>("./Assets/exit.png",
                                                           0, 0, 532, 258);
    buttonExit->sprite->getSprite().setScale(1, 1);
    buttonExit->transform = std::make_shared<TransformComponent>();
    buttonExit->transform->setPosition(135, 270);

    menu.push_back(buttonPlay);
    menu.push_back(buttonExit);

    selectedButton = 1;
}

void GameMenu::MoveUp() {
    selectedButton--;

    if (selectedButton >= 0) {
        menu[selectedButton]->sprite->getSprite().setTextureRect(sf::IntRect(0, 258, 532, 258));
        menu[selectedButton + 1]->sprite->getSprite().setTextureRect(sf::IntRect(0, 0, 532, 258));
    } else {
        menu[0]->sprite->getSprite().setTextureRect(sf::IntRect(0, 0, 532, 258));
        selectedButton = buttonsMax - 1;
        menu[selectedButton]->sprite->getSprite().setTextureRect(sf::IntRect(0, 258, 532, 258));
    }
}

void GameMenu::MoveDown() {
    selectedButton++;

    if (selectedButton < buttonsMax) {
        menu[selectedButton - 1]->sprite->getSprite().setTextureRect(sf::IntRect(0, 0, 532, 258));
        menu[selectedButton]->sprite->getSprite().setTextureRect(sf::IntRect(0, 258, 532, 258));
    } else {
        menu[buttonsMax - 1]->sprite->getSprite().setTextureRect(sf::IntRect(0, 0, 532, 258));
        selectedButton = 0;
        menu[selectedButton]->sprite->getSprite().setTextureRect(sf::IntRect(0, 258, 532, 258));
    }

}

void GameMenu::draw(sf::RenderWindow& window) {
    for (auto const& button : menu) {
        button->sprite->getSprite().setPosition(button->transform->getPosition());
        window.draw(button->sprite->getSprite());
    }
}
