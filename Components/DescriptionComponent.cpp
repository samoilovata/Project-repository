#include "DescriptionComponent.hpp"

DescriptionComponent::DescriptionComponent(int posX, int posY, int width, sf::String string, sf::Font& font) {
    description.setFont(font);
    description.setOutlineThickness(3);
    description.setOutlineColor(sf::Color (111, 47, 58));
    description.setCharacterSize(30);
    description.setFillColor(sf::Color::White);
    description.setString(string);

    description.setPosition(posX - (description.getGlobalBounds().width - width * 5) / 2, posY - description.getGlobalBounds().height - 30);
}
