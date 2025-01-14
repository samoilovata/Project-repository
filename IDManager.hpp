#pragma once

class IDManager {
public:
    static bool getIsRender(int& ID);
    static void changeIsRender(int& ID);

    static bool getInInventory(int& ID);
    static void changeInInventory(int& ID);

    static bool getIsCoin(int& ID);
    static void changeIsCoin(int& ID);

    static bool getIsBerry1(int& ID);
    static void changeIsBerry1(int& ID);

    static bool getIsBerry2(int& ID);
    static void changeIsBerry2(int& ID);

    static bool getIsFlower1(int& ID);
    static void changeIsFlower1(int& ID);

    static bool getIsFlower2(int& ID);
    static void changeIsFlower2(int& ID);

    static bool getIsFish1(int& ID);
    static void changeIsFish1(int& ID);

    static bool getIsFish2(int& ID);
    static void changeIsFish2(int& ID);

    static bool getIsSeeds(int& ID);
    static void changeIsSeeds(int& ID);

    static bool getIsPot(int& ID);
    static void changeIsPot(int& ID);
};
