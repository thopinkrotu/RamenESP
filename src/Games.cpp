#include <Games.h>

// declarations of base functions for BaseGame class (mostly empty : to be modified by game dev)
Games::BaseGame::BaseGame() {};

void Games::BaseGame::init() {};
void Games::BaseGame::update(int delta_time) {};
void Games::BaseGame::render(LiquidCrystal_I2C *lcd) {};
void Games::BaseGame::tick(int delta_time, LiquidCrystal_I2C *lcd)
{
    update(delta_time);
    render(lcd);
}

// Games
// Chrome Dino
Games::ChromeDino::ChromeDino() {};

void Games::ChromeDino::init()
{
    jumping = false;
}

void Games::ChromeDino::update(int delta_time) {};
void Games::ChromeDino::render(LiquidCrystal_I2C *lcd) {};

// Test Game
Games::TestGame::TestGame() {};

void Games::TestGame::init() {};
void Games::TestGame::update(int delta_time) {};
void Games::TestGame::render(LiquidCrystal_I2C *lcd)
{
    lcd->clear();
    lcd->setCursor(0, 0);
    lcd->print("Hello, Test Game");
}
