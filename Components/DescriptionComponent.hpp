#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include "../ECS/Component.hpp"

class DescriptionComponent : public Component {
public:
    DescriptionComponent(int posX, int posY, std::string string, sf::Font& font);

    sf::Text description;

    int positionX;
    int positionY;

    void setPosition(int y, int x);
};
