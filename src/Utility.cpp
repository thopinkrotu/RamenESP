#include <Utility.h>

#include <string>
#include <Arduino.h>

const int JOYSTICK_X = 27;
const int JOYSTICK_Y = 26;
const int JOYSTICK_DOWN = 25;

const int PAUSE_PIN = 32;
bool is_paused_down = false;

const int MAIN_MENU_PIN = 35;
bool is_menu_down = false;

const int SELECT_PIN = 34;
bool is_select_down = false;

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

bool Utility::pressedPaused()
{
    if (!is_paused_down && digitalRead(PAUSE_PIN))
    {
        Serial.println("PAUSED");
        is_paused_down = true;
        return true;
    }

    else if (!digitalRead(PAUSE_PIN))
    {
        is_paused_down = false;
    }

    return false;
}

bool Utility::pressedMenu()
{
    if (!is_menu_down && digitalRead(MAIN_MENU_PIN))
    {
        Serial.println("MENU");
        is_menu_down = true;
        return true;
    }

    else if (!digitalRead(MAIN_MENU_PIN))
    {
        is_menu_down = false;
    }

    return false;
}

bool Utility::pressedSelect()
{
    if (!is_select_down && digitalRead(SELECT_PIN))
    {
        Serial.println("SELECT");
        is_select_down = true;
        return true;
    }

    else if (!digitalRead(SELECT_PIN))
    {
        is_select_down = false;
    }

    return false;
}
