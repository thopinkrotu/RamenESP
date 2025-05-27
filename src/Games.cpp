#include <Games.h>

// declarations of base functions for BaseGame class (mostly empty : to be modified by game dev)
Games::BaseGame::BaseGame() {};

void Games::BaseGame::init() {};
void Games::BaseGame::update(int delta_time) {};
void Games::BaseGame::render(LcdInterface *lcd) {};
void Games::BaseGame::tick(int delta_time, LcdInterface *lcd)
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
void Games::ChromeDino::render(LcdInterface *lcd) {};

// Test Game
Games::TestGame::TestGame() {};

void Games::TestGame::init()
{
    chars[0] = 0;
};
void Games::TestGame::update(int delta_time) {};
void Games::TestGame::render(LcdInterface *lcd)
{
    lcd->clear();
    lcd->setCursor(0, 0);
    lcd->print("Hello, Test Game");
    lcd->setCursor(0, 1);
    lcd->write(0);
}
