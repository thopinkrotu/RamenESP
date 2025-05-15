#include <LcdInterface.h>

LcdInterface::LcdInterface(LiquidCrystal_I2C *lcd)
{
    this->lcd = lcd;

    cursor[0] = 0;
    cursor[1] = 0;
}

void LcdInterface::setCursor(int x, int y)
{
    cursor[0] = x;
    cursor[1] = y;
}

void LcdInterface::print(std::string text)
{
    if (text.length() == 0)
    {
        return;
    }

    for (int i = 0; i < text.length(); i++)
    {
        display_char[cursor[0]][cursor[1]] = &text.at(i);
        display_custom[cursor[0]][cursor[1]] = -1;

        cursor[0] += 1;
        if (cursor[0] >= 20)
        {
            break;
        }
    }

    changed = true;
}

void LcdInterface::write(int char_id)
{
    if (char_id < 0)
    {
        return;
    }

    display_char[cursor[0]][cursor[1]] = (char *)" ";
    display_custom[cursor[0]][cursor[1]] = char_id;

    changed = true;
}

void LcdInterface::clear()
{
    for (int x = 0; x < 20; x++)
    {
        for (int y = 0; y < 4; y++)
        {
            display_char[x][y] = (char *)" ";
            display_custom[x][y] = -1;
        }
    }
}

void LcdInterface::render()
{
    lcd->clear();

    for (int y = 0; y < 4; y++)
    {
        std::string text = "";

        for (int x = 0; x < 20; x++)
        {
            text.append(display_char[x][y]);
        }

        lcd->setCursor(0, y);
        lcd->print(text.c_str());
    }

    for (int x = 0; x < 20; x++)
    {
        for (int y = 0; y < 4; y++)
        {
            if (display_custom[x][y] >= 0)
            {
                lcd->setCursor(x, y);
                lcd->write(byte(display_custom[x][y]));
            }
        }
    }

    changed = false;
}
