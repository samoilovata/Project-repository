#pragma once
#include <iostream>
#include "SFML/Graphics.hpp"
#include "../ECS/Component.hpp"

class DescriptionComponent : public Component {
public:
    DescriptionComponent(int posX, int posY, sf::String string, sf::Font& font);

    sf::Text description;
};
