#ifndef GAMES_H
#define GAMES_H

#include <LcdInterface.h>

#include <vector>

const int MAX_CUSTOM_CHARS = 10;

namespace Games
{
    class BaseGame
    {
    private:
    public:
        // index in this list is refering to the array "chars" in namespace Chars in file Chars.h
        // index in this list is also the index used when rendering the char
        std::vector<int> chars = {};

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

        void init() override;
        void update(int delta_time) override;
        void render(LcdInterface *lcd) override;
    };

    class Snake : public BaseGame
    {
    private:
        std::string direction = "right";
        std::vector<std::vector<int>> segments = {};

        std::vector<int> start_pos = {0, 0};

        // in sqares per second
        int speed = 2;
        int move_counter = 0;

    public:
        Snake();

        void init() override;
        void update(int delta_time) override;
        void render(LcdInterface *lcd) override;

        void newApple();
    };
};

#endif