#include "DescriptionComponent.hpp"

void DescriptionComponent::setPosition(int y, int x) {
    positionY = y - 300;
    positionX = x - 0.256 * width / 2;
}

DescriptionComponent::DescriptionComponent(int posX, int posY, int descriptionWidth, int descriptionHeight, int descriptionX, int descriptionY) {
    x = descriptionX;
    y = descriptionY;
    width = descriptionWidth;
    height = descriptionHeight;
    setPosition(posX, posY);
}
