#include <Games.h>

// declarations of base functions for BaseGame class (mostly empty : to be modified by game dev)
Games::BaseGame::BaseGame(LiquidCrystal_I2C *lcd) { init(lcd); };
Games::BaseGame::BaseGame() {};

void Games::BaseGame::init(LiquidCrystal_I2C *lcd) {};
void Games::BaseGame::update(int delta_time) {};
void Games::BaseGame::render() {};
void Games::BaseGame::tick(int delta_time)
{
    update(delta_time);
    render();
}

// Games
Games::TestGame::TestGame(LiquidCrystal_I2C *lcd)
{
    init(lcd);
}

Games::TestGame::TestGame()
{
}

void Games::TestGame::init(LiquidCrystal_I2C *lcd)
{
}

void Games::TestGame::tick(int delta_time)
{
}

// Muss auch essen :)
// komm vielleicht nachher wieder
//&& was heßt denn vieleicht ;)
