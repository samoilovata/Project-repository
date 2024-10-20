#pragma once
#include <unordered_map>
#include <SFML/Window/Keyboard.hpp>
#include "../ECS/Component.hpp"

class InputComponent : public Component {
public:
    std::unordered_map<sf::Keyboard::Key, bool> keyStatus;

    bool keyPressed(sf::Keyboard::Key key);
    void setKey(sf::Keyboard::Key key, bool pressed);
};
