#include "InputComponent.hpp"

bool InputComponent::keyPressed(sf::Keyboard::Key key) {
    auto it = keyStatus.find(key);
    if (it != keyStatus.end()) {
        return it -> second;
    }
    else return false;
}

void InputComponent::setKey(sf::Keyboard::Key key, bool pressed) {
    keyStatus[key] = pressed;
}
