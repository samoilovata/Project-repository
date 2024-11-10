#pragma once
#include <string>
#include <memory>
#include "ECS/Entity.hpp"
#include "Entities/PlayerEntity.hpp"
#include "Entities/InventoryEntity.hpp"
#include "Entities/ObjectEntity.hpp"

class IDManager {
    bool getIsRender(int& ID);
    void changeIsRender(int& ID);

    bool getInInventory(int& ID);
    void changeInInventory(int& ID);
};