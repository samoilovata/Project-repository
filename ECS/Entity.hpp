#pragma once
#include <vector>
#include <memory>
#include "Component.hpp"

class Entity {
public:
    void addComponent(std::shared_ptr<Component> ptrComponent);
    std::shared_ptr<Component> getComponent(std::shared_ptr<Component> ptrComponent);

private:
    std::vector<std::shared_ptr<Component>> vectorComponent;
};
