#include "DescriptionComponent.hpp"

void DescriptionComponent::setPosition(int y, int x) {
    positionY = y - 200;
    positionX = x + 100 / 2;
}

DescriptionComponent::DescriptionComponent(int posX, int posY, std::string string, sf::Font& font) {
    setPosition(posX, posY);
    description.setFont(font);
    description.setOutlineThickness(3);
    description.setOutlineColor(sf::Color::Black);
    description.setCharacterSize(45);
    description.setFillColor(sf::Color::White);
    description.setString(string);
    description.setPosition(positionX, positionY);
}
