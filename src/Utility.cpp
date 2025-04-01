#include <Utility.h>

#include <string>
#include <Arduino.h>

const int JOYSTICK_X = 27;
const int JOYSTICK_Y = 26;
const int JOYSTICK_DOWN = 25;

std::string Utility::getStickDirection()
{
    // threshold from 0 - 1
    float threshold = 0.6f;

    // get axis (-2048 to 2048)
    float x, y;
    x = analogRead(JOYSTICK_X) - 2048;
    y = analogRead(JOYSTICK_Y) - 2048;

    // normalize values
    x = x / 2048;
    y = y / 2048;

    // apply threshold
    if (abs(x) < threshold && abs(y) < threshold)
    {
        return "center";
    }

    if (abs(x) > abs(y))
    {
        if (x >= 0)
        {
            return "down";
        }
        else
        {
            return "up";
        }
    }
    else
    {
        if (y >= 0)
        {
            return "left";
        }
        else
        {
            return "right";
        }
    }
}
