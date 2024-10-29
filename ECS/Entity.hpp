#pragma once
#include <vector>
#include <memory>
#include "Component.hpp"

class Entity {
public:
    virtual ~Entity() = default;

    void addComponent(std::shared_ptr<Component> ptrComponent);

    template<typename T>
    std::shared_ptr<T> getComponent();

    void changeValue();
    bool getValue();

protected:
    std::vector<std::shared_ptr<Component>> vectorComponent;
    bool isRender = true;
};
