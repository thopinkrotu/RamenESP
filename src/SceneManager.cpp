#include <string>
#include <Arduino.h>
#include <LcdInterface.h>

#include <SceneManager.h>
#include <Utility.h>
#include <Chars.h>

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

        current = current_selected;

        for (int i = 0; i < MAX_CUSTOM_CHARS; i++)
        {
            if (games[current]->chars[i] != 0)
            {
                lcd->createChar((uint8_t)i, Chars::chars[games[current]->chars[i]]);
            }
        }
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

    if (!in_main_menu && !paused)
    {
        games[current]->update(delta_time);
    }
}

void SceneManager::render()
{
    if (boot)
    {
        boot_anim_render();
        lcd->render();
        return;
    }

    lcd->clear();

    if (in_main_menu)
    {
        lcd->setCursor(0, 0);
        lcd->write(0, true);

        lcd->setCursor(19, 0);
        lcd->write(1, true);

        lcd->setCursor(0, 1);
        lcd->print(game_names[current_selected].c_str());

        changed = false;
    }

    else if (paused)
    {
        // "12345678901234567890"
        // "   - - PAUSED - -   "
        int print_x = (int)(9 - game_names[current_selected].length() / 2);
        lcd->setCursor(print_x, 0);
        lcd->print(game_names[current_selected]);

        lcd->setCursor(0, 1);
        lcd->print("   - - PAUSED - -   ");
    }

    else
    {
        games[current]->render(lcd);
    }

    lcd->render();
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
        boot = false;
        lcd->clear();
    }
}
