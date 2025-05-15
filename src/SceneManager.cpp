#include <string>
#include <Arduino.h>
#include <LcdInterface.h>

#include <SceneManager.h>
#include <Utility.h>

SceneManager::SceneManager(LcdInterface *lcd)
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
        boot_counter += delta_time;
        return;
    }

    // act acording to button presses
    if (Utility::pressedPaused() && !in_main_menu)
    {
        paused = !paused;
    }

    if (Utility::pressedMenu())
    {
        paused = false;
        in_main_menu = true;
    }

    if (Utility::pressedSelect() && in_main_menu)
    {
        in_main_menu = false;
        paused = false;
    }

    if (in_main_menu)
    {
        // actualy switch scenes (games)
        std::string direction = Utility::getStickDirection();

        if (direction == "right" && joystick_is_resting)
        {
            current_selected += 1;
            changed = true;
            joystick_is_resting = false;
        }

        else if (direction == "left" && joystick_is_resting)
        {
            current_selected -= 1;
            changed = true;
            joystick_is_resting = false;
        }

        else if (direction == "center")
        {
            joystick_is_resting = true;
        }

        current_selected += game_count;
        current_selected %= game_count;
    }
}

void SceneManager::render()
{
    if (boot)
    {
        boot_anim_render();
        return;
    }

    if (in_main_menu && changed)
    {
        lcd->clear();

        lcd->setCursor(0, 0);
        lcd->write(byte(0));

        lcd->setCursor(19, 0);
        lcd->write(byte(1));

        lcd->setCursor(0, 1);
        lcd->print(game_names[current_selected].c_str());

        changed = false;
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
        games[current]->tick(delta_time, lcd);
    }
}

void SceneManager::tick()
{
    update();
    render();
}

void SceneManager::boot_anim_render()
{
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
