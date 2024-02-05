#pragma once
#include <vector>

#include "RenderWindow.hpp"
#include "Entity.hpp"
#include "Utils.hpp"

class Game
{
public:
    Game();
    void run();
private:
    RenderWindow window;
    std::vector<Entity> entities;
    bool gameRunning;
};