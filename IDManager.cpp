#include "IDManager.hpp"

bool IDManager::getIsRender(int& ID) {
    return (ID & 1);
}

void IDManager::changeIsRender(int& ID) {
    if (getIsRender(ID)) ID = (ID & ~1);
    else ID = (ID | 1);
}

bool IDManager::getInInventory(int& ID) {
    return (ID & (1 << 1));
}

void IDManager::changeInInventory(int& ID) {
    if (getInInventory(ID)) ID = (ID & ~(1 << 1));
    else ID = (ID | (1 << 1));
}

bool IDManager::getIsCoin(int& ID) {
    return (ID & (1 << 2));
}

void IDManager::changeIsCoin(int& ID) {
    if (getIsCoin(ID)) ID = (ID & ~(1 << 2));
    else ID = (ID | (1 << 2));
}
