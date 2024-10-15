#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "../ECS/Component.hpp"

class BoundsComponent : public Component {
public:
    void setBounds(sf::Sprite& sprite);
    void setBounds(sf::Vector2f& position);
    sf::FloatRect getBounds();

private:
    sf::FloatRect bounds;
};
