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

bool IDManager::getIsBerry1(int &ID) {
    return (ID & (1 << 3));
}

void IDManager::changeIsBerry1(int &ID) {
    if (getIsBerry1(ID)) ID = (ID & ~(1 << 3));
    else ID = (ID | (1 << 3));
}

bool IDManager::getIsBerry2(int &ID) {
    return (ID & (1 << 4));
}

void IDManager::changeIsBerry2(int &ID) {
    if (getIsBerry2(ID)) ID = (ID & ~(1 << 4));
    else ID = (ID | (1 << 4));
}

bool IDManager::getIsFlower1(int &ID) {
    return (ID & (1 << 5));
}

void IDManager::changeIsFlower1(int &ID) {
    if (getIsFlower1(ID)) ID = (ID & ~(1 << 5));
    else ID = (ID | (1 << 5));
}

bool IDManager::getIsFlower2(int &ID) {
    return (ID & (1 << 6));
}

void IDManager::changeIsFlower2(int &ID) {
    if (getIsFlower2(ID)) ID = (ID & ~(1 << 6));
    else ID = (ID | (1 << 6));
}

bool IDManager::getIsFish1(int &ID) {
    return (ID & (1 << 7));
}

void IDManager::changeIsFish1(int &ID) {
    if (getIsFish1(ID)) ID = (ID & ~(1 << 7));
    else ID = (ID | (1 << 7));
}

bool IDManager::getIsFish2(int &ID) {
    return (ID & (1 << 8));
}

void IDManager::changeIsFish2(int &ID) {
    if (getIsFish2(ID)) ID = (ID & ~(1 << 8));
    else ID = (ID | (1 << 8));
}

bool IDManager::getIsSeeds(int &ID) {
    return (ID & (1 << 9));
}

void IDManager::changeIsSeeds(int &ID) {
    if (getIsSeeds(ID)) ID = (ID & ~(1 << 9));
    else ID = (ID | (1 << 9));
}

bool IDManager::getIsPot(int &ID) {
    return (ID & (1 << 10));
}

void IDManager::changeIsPot(int &ID) {
    if (getIsPot(ID)) ID = (ID & ~(1 << 10));
    else ID = (ID | (1 << 10));
}
