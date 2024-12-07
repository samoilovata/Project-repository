#include <SFML/Window/Keyboard.hpp>
#include "InputSystem.hpp"

void InputSystem::update(sf::Window& window) {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
        else if (event.type == sf::Event::KeyPressed) {
            EntityManager::keyStatus[event.key.code] = true;
        }
        else if (event.type == sf::Event::KeyReleased) {
            EntityManager::keyStatus[event.key.code] = false;
        }
    }
}

void InputSystem::update(EntityManager& entityManager, sf::Time& deltaTime) {

}
