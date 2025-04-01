#include <string>
#include <LiquidCrystal_I2C.h>

#include <SceneManager.h>
#include <Utility.h>

SceneManager::SceneManager(LiquidCrystal_I2C *lcd)
{
    this->lcd = lcd;
}

void SceneManager::update()
{
    // calculation of delta time
    time = millis();
    delta_time = time - last_time;
    last_time = time;

    // prevent too big lags from interrupting any kind of interaction (lags bigger than 0.5 sec)
    if (delta_time > 500)
    {
        delta_time = 0;
    }

    // for bootup animation
    if (boot)
    {
        boot_anim_tick();
        return;
    }
    
    // actualy switch scenes (games)
    std::string direction = Utility::getStickDirection();

    if (direction == "right")
    {
        current_selected += 1;
    }

    else if (direction == "left")
    {
        current_selected -= 1;
    }

    current_selected += game_count;
    current_selected %= game_count;
}

void SceneManager::render()
{
    if (in_main_menu)
    {
        lcd->setCursor(0, 1);
        lcd->print(game_names[current_selected].c_str());
    }

    else if (paused)
    {
        // "12345678901234567890"
        // "   - - PAUSED - -   "
        lcd->setCursor(0, 1);
        lcd->print("   - - PAUSED - -   ");
    }

    else
    {
        games[current]->tick(delta_time);
    }
}

void SceneManager::tick()
{
    update();
    render();
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
        lcd->print("     RAMEN-ESP      ");
    }

    if (boot_counter >= boot_time)
    {
        lcd->clear();
        boot = false;
    }
}
