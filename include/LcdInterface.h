#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H

#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <string>

class LcdInterface
{
private:
    LiquidCrystal_I2C *lcd;
    bool changed = false;

    char *display_char[20][4];
    int display_custom[20][4];

    int cursor[2];

public:
    LcdInterface(LiquidCrystal_I2C *lcd);

    void setCursor(int x, int y);
    void print(std::string text);
    void write(int char_id);
    void clear();

    void render();
};

#endif