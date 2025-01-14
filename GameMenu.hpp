#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "Components/SpriteComponent.hpp"
#include "Components/TransformComponent.hpp"

struct Button {
    std::shared_ptr<SpriteComponent> sprite;
    std::shared_ptr<TransformComponent> transform;
};

class GameMenu {
    int buttonsMax = 2;
    int selectedButton;

    std::vector<std::shared_ptr<Button>> menu;

    std::shared_ptr<Button> buttonPlay;
    std::shared_ptr<Button> buttonExit;

    sf::Color menu_text_color = sf::Color::White;
    sf::Color chose_text_color = sf::Color::Yellow;
    sf::Color border_color = sf::Color::Black;

public:
    GameMenu();

    void draw(sf::RenderWindow& window);
    void MoveUp();
    void MoveDown();

    int getSelectedMenuNumber() const {
        return selectedButton;
    }
};
