#pragma once
#include <vector>

#include "RenderWindow.hpp"
#include "Entity.hpp"
#include "Utils.hpp"
#include "Timestepper.hpp"

class Game
{
public:
    Game();
    void run();
private:
    RenderWindow window;
    TimeStepper timeStepper;
    std::vector<Entity> entities;
    bool gameRunning;
};