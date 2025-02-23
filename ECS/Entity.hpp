#pragma once
#include <vector>
#include <memory>
#include "Component.hpp"

enum typeEntity {
    OBJECT,
    PLAYER,
    INVENTORY,
    INTERACTIVE_OBJECT,
    LOCATION_OBJECT,
    STATIC_OBJECT,
    EMPTY_OBJECT
};

class Entity {
public:
    virtual ~Entity() = default;

    void addComponent(std::shared_ptr<Component> ptrComponent);
    void deleteComponent();

    template<typename T>
    std::shared_ptr<T> getComponent();

    typeEntity flag;
    int ID;
    int location;

protected:
    std::vector<std::shared_ptr<Component>> vectorComponent;
};
