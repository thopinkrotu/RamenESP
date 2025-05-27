#ifndef GAMES_H
#define GAMES_H

#include <LcdInterface.h>

const int MAX_CUSTOM_CHARS = 10;

namespace Games
{
    class BaseGame
    {
    private:
    public:
        // dont use 0 as index to your custom char because it will be ignored when loading chars onto the display (just start at 1)
        // index in this list is refering to the array "chars" in namespace Chars in file Chars.h
        int chars[MAX_CUSTOM_CHARS] = {};

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