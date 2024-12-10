#pragma once

class IDManager {
public:
    static bool getIsRender(int& ID);
    static void changeIsRender(int& ID);

    static bool getInInventory(int& ID);
    static void changeInInventory(int& ID);

    static bool getIsCoin(int& ID);
    static void changeIsCoin(int& ID);
};
