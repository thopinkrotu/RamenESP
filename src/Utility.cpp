#include <Utility.h>

#include <string>
#include <Arduino.h>

const int JOYSTICK_X = 27;
const int JOYSTICK_Y = 26;
const int JOYSTICK_DOWN = 25;

const int PAUSE_PIN = 34;
bool is_paused_down = false;

const int MAIN_MENU_PIN = 35;
bool is_menu_down = false;

const int SELECT_PIN = 32;
bool is_select_down = false;

std::string Utility::getStickDirection()
{
    // threshold from 0 - 1
    float threshold = 0.6f;

    // get axis (-2048 to 2048)
    float x, y;
    x = analogRead(JOYSTICK_X) - 2048;
    y = analogRead(JOYSTICK_Y) - 2048;

    // Serial.print(x);
    // Serial.print(", ");
    // Serial.println(y);

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
    bool value = digitalRead(PAUSE_PIN);

    // Serial.print("PAUSED: ");
    // Serial.println(value);

    if (!is_paused_down && value)
    {
        // Serial.println("PAUSED");
        is_paused_down = true;
        return true;
    }

    else if (!value)
    {
        is_paused_down = false;
    }

    return false;
}

bool Utility::pressedMenu()
{
    bool value = digitalRead(MAIN_MENU_PIN);

    // Serial.print("MENU: ");
    // Serial.println(value);

    if (!is_menu_down && value)
    {
        // Serial.println("MENU");
        is_menu_down = true;
        return true;
    }

    else if (!value)
    {
        is_menu_down = false;
    }

    return false;
}

bool Utility::pressedSelect()
{
    bool value = digitalRead(SELECT_PIN);

    // Serial.print("SELECT: ");
    // Serial.println(value);

    if (!is_select_down && value)
    {
        // Serial.println("SELECT");
        is_select_down = true;
        return true;
    }

    else if (!value)
    {
        is_select_down = false;
    }

    return false;
}

bool Utility::areCharArraysEqual(char arr1[20][4], char arr2[20][4])
{
    for (int x = 0; x < 20; x++)
    {
        for (int y = 0; y < 4; y++)
        {
            if (arr1[x][y] != arr2[x][y])
            {
                return false;
            }
        }
    }

    return true;
}

bool Utility::areIntArraysEqual(int arr1[20][4], int arr2[20][4])
{
    for (int x = 0; x < 20; x++)
    {
        for (int y = 0; y < 4; y++)
        {
            if (arr1[x][y] != arr2[x][y])
            {
                return false;
            }
        }
    }

    return true;
}

// hydrogen.exe
