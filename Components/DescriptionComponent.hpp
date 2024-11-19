#pragma once
#include <iostream>
#include "../ECS/Component.hpp"

class DescriptionComponent : public Component {
public:
    DescriptionComponent(int posX, int posY, int descriptionWidth, int descriptionHeight, int descriptionX, int descriptionY);

    int positionX;
    int positionY;
    int width;
    int height;
    int x;
    int y;

    void setPosition(int y, int x);
};
