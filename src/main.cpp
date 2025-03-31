#include <LiquidCrystal_I2C.h>

#include <Chars.h>
#include <SceneManager.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);
SceneManager scene_manager(&lcd);

void setup() {
    // init lcd display
    lcd.init();
    lcd.backlight();

    // upload chars to lcd display
    for (int i = 0; i < Chars::char_count; i++)
    {
        lcd.createChar(i, Chars::chars[i]);
    }
}

void loop() {
    scene_manager.tick();
}
