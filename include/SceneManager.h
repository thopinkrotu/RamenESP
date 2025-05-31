#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

#include <LcdInterface.h>

#include <Games.h>
#include <string>

class SceneManager
{
private:
    LcdInterface *lcd;

    int delta_time = 0;
    int time = 0;
    int last_time = 0;

    bool boot = true;
    int boot_time = 5000;
    int boot_counter = 0;

    int game_count = 3;
    Games::BaseGame *games[3] = {
        new Games::TestGame(),
        new Games::TestGame(),
        new Games::Snake()};

    std::string game_names[3] = {
        "Test Game",
        "Test Game 2",
        "Snake"};

    bool paused = false;
    bool in_main_menu = true;

    bool joystick_is_resting = true;
    int current_selected = 0;
    int current = 0;

    bool changed = true;

public:
    SceneManager(LcdInterface *lcd);

    void tick();
    void update();
    void render();

    void boot_anim_render();
};

#endif