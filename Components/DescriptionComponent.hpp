#pragma once
#include <iostream>
#include "../ECS/Component.hpp"

class DescriptionComponent : public Component {
public:
    int x;
    int y;

    void setPosition(int y);
};
