#ifndef UTILITY_H
#define UTILITY_H

#include <string>

namespace Utility
{
    std::string getStickDirection();

    bool pressedPaused();
    bool pressedMenu();
    bool pressedSelect();
}

#endif