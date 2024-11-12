#include "IDManager.hpp"

bool IDManager::getIsRender(int& ID) {
    return (ID & 1);
}

void IDManager::changeIsRender (int& ID) {
    if (getIsRender(ID)) ID = (ID & ~1);
    else ID = (ID | 1);
}

bool IDManager::getInInventory(int& ID) {
    return (ID & (1 << 1));
}

void IDManager::changeInInventory (int& ID) {
    if (getIsRender(ID)) ID = (ID & ~(1 << 1));
    else ID = (ID | (1 << 1));
}
