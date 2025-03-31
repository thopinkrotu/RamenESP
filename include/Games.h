#ifndef GAMES_H
#define GAMES_H

#include <LiquidCrystal_I2C.h>

namespace Games
{
    class BaseGame
    {
    private:
        LiquidCrystal_I2C* lcd;

    public:
        BaseGame();
        BaseGame(LiquidCrystal_I2C* lcd);

        virtual void init(LiquidCrystal_I2C* lcd);
        virtual void tick(int delta_time);
    };

    class TestGame : public BaseGame
    {
    private:
    public:
        TestGame();
        TestGame(LiquidCrystal_I2C* lcd);

        void init(LiquidCrystal_I2C* lcd) override;
        void tick(int delta_time) override;
    };
};

#endif