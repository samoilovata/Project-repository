#pragma once
#include <unordered_map>
#include "../ECS/Component.hpp"
#include <SFML/Window/Keyboard.hpp>

class InputComponent : public Component {
public:
    std::unordered_map<sf::Keyboard::Key, bool> KeyStat;

    bool IsTheKeyPressed(sf::Keyboard::Key key) {
        std::unordered_map<sf::Keyboard::Key, bool>::iterator it = KeyStat.find(key);
        if (it != KeyStat.end()) {
            return it -> second;
        }
        else return false;
    }

    void SetKey (sf::Keyboard::Key key, bool pressed) {
        KeyStat[key] = pressed;
    }

};


