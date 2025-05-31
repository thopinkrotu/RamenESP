#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H

#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <string>

class LcdInterface
{
private:
    LiquidCrystal_I2C *lcd;

    char display_char[20][4];
    char display_char_before[20][4];

    int display_custom[20][4];
    int display_custom_before[20][4];

    int cursor[2];

public:
    LcdInterface(LiquidCrystal_I2C *lcd);

    void createChar(uint8_t char_id, byte char_map[]);

    void setCursor(int x, int y);
    void print(std::string text);
    void write(int char_id, bool real_id = false);
    void clear();

    void render();
};

#endif