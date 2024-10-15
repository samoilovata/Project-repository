#pragma once
#include <vector>
#include <memory>
#include "Component.hpp"

class Entity {
public:
    void addComponent(std::shared_ptr<Component> ptrComponent);

    template<typename T>
    std::shared_ptr<T> getComponent();

private:
    std::vector<std::shared_ptr<Component>> vectorComponent;
};
