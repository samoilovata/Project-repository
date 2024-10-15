#pragma once
#include "../ECS/Component.hpp"
#include <SFML/System.hpp>

class TransformComponent : public Component {
public:
    TransformComponent(float x = 0, float y = 0);

    void setPosition(float x, float y);
    void setPosition(const sf::Vector2f& pos);
    void translate(float x, float y);
    void translate(const sf::Vector2f& offset);
    sf::Vector2f getPosition() const;

private:
    sf::Vector2f position;
};
