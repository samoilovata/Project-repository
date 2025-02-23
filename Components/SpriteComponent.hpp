#pragma once
#include <string>
#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>
#include "../ECS/Component.hpp"

class SpriteComponent : public Component {
public:
    SpriteComponent(const std::string &filePath, int left = 0, int top = 0, int width = 0, int height = 0);
    void setPosition(float x, float y);
    void setTexture(int left, int top, int width, int height);
    sf::Sprite& getSprite();

    sf::Sprite sprite;
    std::shared_ptr<sf::Texture> texture;
};
