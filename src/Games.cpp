#include <Games.h>
#include <Utility.h>

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
// Snake
Games::Snake::Snake()
{
    chars.insert(chars.begin(), 1);
};

void Games::Snake::init()
{
    direction = "right";
    segments.clear();
    segments.insert(segments.begin(), start_pos);
};

void Games::Snake::newApple()
{
    int new_pos[2];

    bool found = false;
    while (!found)
    {
        new_pos[0] = random(0, 20);
        new_pos[1] = random(0, 4);

        found = true;
        for (int i = 0; i < segments.size(); i++)
        {
            if (segments[i][0] == new_pos[0] && segments[i][1] == new_pos[1])
            {
                found = false;
            }
        }
    }
};

void Games::Snake::update(int delta_time)
{
    move_counter += delta_time;

    std::string temp_direction = Utility::getStickDirection();

    Serial.println(temp_direction.c_str());

    if (temp_direction != "center")
    {
        direction = temp_direction;
    }

    if (move_counter >= (int)(1000 / speed))
    {
        move_counter -= (int)(1000 / speed);

        std::vector<int> new_pos;

        Serial.println(direction.c_str());
        Serial.println("-----");

        if (direction == "right")
        {
            new_pos = {segments[0][0] + 1, segments[0][1]};
        }

        else if (direction == "left")
        {
            new_pos = {segments[0][0] - 1, segments[0][1]};
        }

        else if (direction == "up")
        {
            new_pos = {segments[0][0], segments[0][1] - 1};
        }

        else if (direction == "down")
        {
            new_pos = {segments[0][0], segments[0][1] + 1};
        }

        if (segments.size() > 0)
        {
            segments.pop_back();
        }

        Serial.println(new_pos.size());

        new_pos[0] += 20;
        new_pos[1] += 4;

        new_pos[0] %= 20;
        new_pos[1] %= 4;

        segments.insert(segments.begin(), new_pos);
    }
};

void Games::Snake::render(LcdInterface *lcd)
{
    for (int i = 0; i < segments.size(); i++)
    {
        Serial.print(segments[i][0]);
        Serial.print(", ");
        Serial.println(segments[i][1]);

        lcd->setCursor(segments[i][0], segments[i][1]);
        lcd->write(0);
    }
}

// Chrome Dino
Games::ChromeDino::ChromeDino() {};

void Games::ChromeDino::init()
{
    jumping = false;
}

void Games::ChromeDino::update(int delta_time) {};
void Games::ChromeDino::render(LcdInterface *lcd) {};

// Test Game
Games::TestGame::TestGame()
{
    chars.insert(chars.begin(), 0);
};

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
