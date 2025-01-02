#include "DescriptionComponent.hpp"

DescriptionComponent::DescriptionComponent(int posX, int posY, sf::String string, sf::Font& font) {
    description.setFont(font);
    description.setOutlineThickness(2);
    description.setOutlineColor(sf::Color (51, 43, 45));
    description.setCharacterSize(40);
    description.setFillColor(sf::Color::White);
    description.setString(string);

    description.setPosition(posX - description.getGlobalBounds().width / 2 + 15, posY - description.getGlobalBounds().height - 30);
}
