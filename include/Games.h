#ifndef GAMES_H
#define GAMES_H

#include <LiquidCrystal_I2C.h>

namespace Games
{
    class BaseGame
    {
    private:
    public:
        BaseGame();

        virtual void init();
        virtual void tick(int delta_time, LiquidCrystal_I2C *lcd);
        virtual void update(int delta_time);
        virtual void render(LiquidCrystal_I2C *lcd);
    };

    class TestGame : public BaseGame
    {
    private:
    public:
        TestGame();

        void init() override;
        void update(int delta_time) override;
        void render(LiquidCrystal_I2C *lcd) override;
    };
    
    class ChromeDino : public BaseGame
    {
    private:
        bool jumping;

    public:
        ChromeDino();
        ChromeDino(LiquidCrystal_I2C *lcd);

        void init() override;
        void update(int delta_time) override;
        void render(LiquidCrystal_I2C *lcd) override;
    };
};

#endif