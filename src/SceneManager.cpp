#include <SceneManager.h>

#include <string>

#include <LiquidCrystal_I2C.h>

SceneManager::SceneManager(LiquidCrystal_I2C* lcd)
{
    this->lcd = lcd;
}

void SceneManager::tick()
{
    // calculation of delta time
    time = millis();
    delta_time = time - last_time;
    last_time = time;

    // prevent too big lags to interrupt any kind of interaction (bigger than 0.5 sec)
    if (delta_time > 500)
    {
        delta_time = 0;
    }

    // for bootup animation :)
    if (boot)
    {
        boot_anim_tick();
        return;
    }

    lcd->setCursor(0, 0);
    lcd->print("Hello, World!");

    lcd->setCursor(0, 1);
    lcd->print("After boot (2 sec)");

    lcd->setCursor(0, 2);
    lcd->print("Time since boot:");

    lcd->setCursor(0, 3);
    lcd->print(std::to_string((int)millis()).c_str());
}

void SceneManager::boot_anim_tick()
{
    boot_counter += delta_time;
    if (boot_counter < 1250)
    {
        // "12345678901234567890"
        // "      WELCOME!      "
        lcd->setCursor(0, 1);
        lcd->print("      WELCOME!      ");
    }

    else if (boot_counter < 2000)
    {
        // "12345678901234567890"
        // "         TO         "
        lcd->setCursor(0, 1);
        lcd->print("         TO         ");
    }

    else if (boot_counter < 5000)
    {
        // "12345678901234567890"
        // "      RAMENESP      "
        lcd->setCursor(0, 1);
        lcd->print("      RAMENESP      ");
    }

    if (boot_counter >= boot_time)
    {
        boot = false;
    }
}
