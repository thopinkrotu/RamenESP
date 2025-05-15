#include <LcdInterface.h>

#include <Utility.h>

LcdInterface::LcdInterface(LiquidCrystal_I2C *lcd)
{
    this->lcd = lcd;

    cursor[0] = 0;
    cursor[1] = 0;

    for (int x = 0; x < 20; x++)
    {
        for (int y = 0; y < 4; y++)
        {
            display_char_before[x][y] = ' ';
        }
    }

    this->clear();
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

    int written = 0;
    for (int i = 0; i < text.length(); i++)
    {
        display_char[cursor[0]][cursor[1]] = text[i];
        display_custom[cursor[0]][cursor[1]] = -1;

        written += 1;
        cursor[0] += 1;
        if (cursor[0] >= 20)
        {
            break;
        }
    }

    cursor[0] -= written;
}

void LcdInterface::write(int char_id)
{
    if (char_id < 0)
    {
        return;
    }

    else if (display_custom[cursor[0]][cursor[1]] == char_id)
    {
        display_char[cursor[0]][cursor[1]] = ' ';
        return;
    }

    display_char[cursor[0]][cursor[1]] = ' ';
    display_custom[cursor[0]][cursor[1]] = char_id;
}

void LcdInterface::clear()
{
    for (int x = 0; x < 20; x++)
    {
        for (int y = 0; y < 4; y++)
        {
            display_char[x][y] = ' ';
            display_custom[x][y] = -1;
        }
    }
}

void LcdInterface::render()
{
    for (int y = 0; y < 4; y++)
    {
        for (int x = 0; x < 20; x++)
        {
            bool charChanged = display_char[x][y] != display_char_before[x][y];
            bool customChanged = display_custom[x][y] != display_custom_before[x][y];

            if (charChanged || customChanged)
            {
                lcd->setCursor(x, y);

                if (display_custom[x][y] >= 0)
                {
                    lcd->write(byte(display_custom[x][y]));
                    display_char_before[x][y] = ' ';
                }
                else
                {
                    lcd->print(display_char[x][y]);
                    display_char_before[x][y] = display_char[x][y];
                }

                display_custom_before[x][y] = display_custom[x][y];
            }
        }
    }
}
