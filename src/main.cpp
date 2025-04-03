#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

#include <Chars.h>
#include <SceneManager.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);
SceneManager scene_manager(&lcd);

const int JOYSTICK_DOWN = 25;

const int PAUSE_PIN = 32;
const int MAIN_MENU_PIN = 35;
const int SELECT_PIN = 34;

void setup()
{
    Serial.begin(9600);

    // pin modes
    pinMode(JOYSTICK_DOWN, INPUT);
    pinMode(PAUSE_PIN, INPUT);
    pinMode(MAIN_MENU_PIN, INPUT);
    pinMode(SELECT_PIN, INPUT);

    // init lcd display
    lcd.init();
    lcd.backlight();

    // upload chars to lcd display
    for (int i = 0; i < Chars::char_count; i++)
    {
        lcd.createChar(i, Chars::chars[i]);
    }
}

void loop()
{
    scene_manager.tick();
}
