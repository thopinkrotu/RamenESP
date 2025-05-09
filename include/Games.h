#ifndef GAMES_H
#define GAMES_H

#include <LiquidCrystal_I2C.h>

namespace Games
{
    class BaseGame
    {
    private:
    protected:
        LiquidCrystal_I2C *lcd;

    public:
        BaseGame();
        BaseGame(LiquidCrystal_I2C *lcd);

        virtual void init(LiquidCrystal_I2C *lcd);
        virtual void tick(int delta_time);
        virtual void update(int delta_time);
        virtual void render();
    };

    class TestGame : public BaseGame
    {
    private:
    public:
        TestGame();
        TestGame(LiquidCrystal_I2C *lcd);

        void init(LiquidCrystal_I2C *lcd) override;
        void update(int delta_time) override;
        void render() override;
    };
    
    class ChromeDino : public BaseGame
    {
    private:
        bool jumping;

    public:
        ChromeDino();
        ChromeDino(LiquidCrystal_I2C *lcd);

        void init(LiquidCrystal_I2C *lcd) override;
        void update(int delta_time) override;
        void render() override;
    };
};

#endif