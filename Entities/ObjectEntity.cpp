#include "ObjectEntity.hpp"

bool ObjectEntity::getInInventory() {
    return inInventory;
}

void ObjectEntity::changeInInventory() {
    if (!inInventory) inInventory = true;
    else inInventory = false;
}
