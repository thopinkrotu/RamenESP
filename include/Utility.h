#ifndef UTILITY_H
#define UTILITY_H

#include <string>

namespace Utility
{
    std::string getStickDirection();

    bool pressedPaused();
    bool pressedMenu();
    bool pressedSelect();

    bool areCharArraysEqual(char arr1[20][4], char arr2[20][4]);
    bool areIntArraysEqual(int arr1[20][4], int arr2[20][4]);
}

#endif