#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

#include <LiquidCrystal_I2C.h>

#include <Games.h>
#include <string>

class SceneManager
{
private:
    LiquidCrystal_I2C* lcd;

    int delta_time = 0;
    int time = 0;
    int last_time = 0;

    bool boot = true;
    int boot_time = 5000;
    int boot_counter = 0;

    int game_count = 1;
    Games::BaseGame* games[1] = {
        new Games::TestGame(lcd)
    };

    std::string game_names[1] = {
        "Test Game"
    };

    bool paused = false;
    bool in_main_menu = true;

    int current_selected = 0;
    int current = 0;

public:
    SceneManager(LiquidCrystal_I2C* lcd);

    void tick();
    void boot_anim_tick();
};

#endif