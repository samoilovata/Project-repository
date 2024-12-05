#include "DescriptionComponent.hpp"

void DescriptionComponent::setPosition(int x, int y) {
    positionX = x - 80 / 2;
    positionY = y - 100;
}

DescriptionComponent::DescriptionComponent(int posX, int posY, sf::String string, sf::Font& font) {
    setPosition(posX, posY);
    description.setFont(font);
    description.setOutlineThickness(3);
    description.setOutlineColor(sf::Color::Black);
    description.setCharacterSize(45);
    description.setFillColor(sf::Color::White);
    description.setString(string);
    description.setPosition(positionX, positionY);
}
