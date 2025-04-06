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
// Chrome Dino
Games::ChromeDino::ChromeDino() {};
Games::ChromeDino::ChromeDino(LiquidCrystal_I2C *lcd) { init(lcd); };

void Games::ChromeDino::init(LiquidCrystal_I2C *lcd)
{
    this->lcd = lcd;
    jumping = false;
}

void Games::ChromeDino::update(int delta_time) {};
void Games::ChromeDino::render() {};

// Test Game
Games::TestGame::TestGame(LiquidCrystal_I2C *lcd) { init(lcd); };
Games::TestGame::TestGame() {};

void Games::TestGame::init(LiquidCrystal_I2C *lcd) { this->lcd = lcd; };
void Games::TestGame::update(int delta_time) {};
void Games::TestGame::render()
{
    lcd->clear();
    lcd->setCursor(0, 0);
    lcd->print("Hello, Test Game");
}
