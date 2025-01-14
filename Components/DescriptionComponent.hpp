#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include "../ECS/Component.hpp"

class DescriptionComponent : public Component {
public:
    DescriptionComponent(int posX, int posY, int width, sf::String string, sf::Font& font);
    void setPosition(sf::Vector2f position, int width);
    void setText(sf::String string);

    sf::Text description;
};
