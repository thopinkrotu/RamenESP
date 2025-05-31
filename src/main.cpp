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

    // upload default chars to lcd display (arrows for menu)
    lcd.createChar(0, Chars::arrow_left);
    lcd.createChar(1, Chars::arrow_right);
}

void loop()
{
    scene_manager.tick();
}
