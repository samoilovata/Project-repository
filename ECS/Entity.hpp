#pragma once
#include <vector>
#include <memory>
#include "Component.hpp"

enum typeEntity {
    object,
    player,
    inventory
};

class Entity {
public:
    virtual ~Entity() = default;

    void addComponent(std::shared_ptr<Component> ptrComponent);

    template<typename T>
    std::shared_ptr<T> getComponent();

    void changeValue();
    bool getValue();

    virtual void changeInInventory();
    virtual bool getInInventory();

    int getID();

    typeEntity flag;

protected:
    std::vector<std::shared_ptr<Component>> vectorComponent;

    bool isRender = true;
    int ID;
};
