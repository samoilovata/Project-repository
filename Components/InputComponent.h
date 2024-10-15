#pragma once
#include <unordered_map>
#include "../ECS/Component.hpp"
#include <SFML/Window/Keyboard.hpp>

class InputComponent : public Component {
public:
    std::unordered_map<sf::Keyboard::Key, bool> keyStatus;

    bool keyPressed(sf::Keyboard::Key key) {
        std::unordered_map<sf::Keyboard::Key, bool>::iterator it = keyStatus.find(key);
        if (it != keyStatus.end()) {
            return it -> second;
        }
        else return false;
    }

    void setKey(sf::Keyboard::Key key, bool pressed) {
        keyStatus[key] = pressed;
    }

};
