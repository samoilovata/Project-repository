#pragma once
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "../ECS/Component.hpp"

class SpriteComponent : public Component {
public:
    SpriteComponent(const std::string &filePath);
    void setPosition(float x, float y);
    sf::Sprite& getSprite();

private:
    sf::Sprite sprite;
    sf::Texture texture;
};
