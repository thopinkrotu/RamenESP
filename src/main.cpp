#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

#include <Chars.h>
#include <SceneManager.h>
#include <LcdInterface.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);
LcdInterface lcd_interface(&lcd);
SceneManager scene_manager(&lcd_interface);

const int JOYSTICK_DOWN = 25;

const int PAUSE_PIN = 34;
const int MAIN_MENU_PIN = 35;
const int SELECT_PIN = 32;

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

    // initialize array values
    lcd_interface.clear();
}

void loop()
{
    // scene_manager.tick();
    lcd_interface.setCursor(0, 0);
    lcd_interface.print("Test, Hello?");
    lcd_interface.setCursor(0, 3);
    lcd_interface.print("Test but down here!");
    lcd_interface.render();
}
