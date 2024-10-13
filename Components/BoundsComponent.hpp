#pragma once
#include <SFML/Graphics.hpp>
#include "../ECS/Component.hpp"

class BoundsComponent : public Component {
public:
    void setBounds(sf::Sprite& sprite);
    sf::FloatRect getBounds();

private:
    sf::FloatRect bounds;
};
