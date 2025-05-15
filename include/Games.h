#ifndef GAMES_H
#define GAMES_H

#include <LcdInterface.h>

namespace Games
{
    class BaseGame
    {
    private:
    public:
        BaseGame();

        virtual void init();
        virtual void tick(int delta_time, LcdInterface *lcd);
        virtual void update(int delta_time);
        virtual void render(LcdInterface *lcd);
    };

    class TestGame : public BaseGame
    {
    private:
    public:
        TestGame();

        void init() override;
        void update(int delta_time) override;
        void render(LcdInterface *lcd) override;
    };

    class ChromeDino : public BaseGame
    {
    private:
        bool jumping;

    public:
        ChromeDino();
        ChromeDino(LcdInterface *lcd);

        void init() override;
        void update(int delta_time) override;
        void render(LcdInterface *lcd) override;
    };
};

#endif