#include <iostream>

#include "Game.hpp"

Game::Game() 
:window("ZEN_GARDEN v1.0", 1280, 720), gameRunning(true), timeStepper(0.01f)
{
    SDL_Texture* tx_grass = window.loadTexture("res/gfx/ground_grass_1.png");

    entities.emplace_back(Vector2f(0, 0), tx_grass);
    entities.emplace_back(Vector2f(30, 0), tx_grass);
    entities.emplace_back(Vector2f(30, 30), tx_grass);
}

void Game::run()
{

    SDL_Event event;

    while (gameRunning)
    {
        int firstTick = SDL_GetTicks();

         timeStepper.update();

         while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
                gameRunning = false;
        }

        if (timeStepper.shouldUpdate())
        {
            // Movement logic
            std::cout << "step" << std::endl;

            timeStepper.reset();
        }

        window.clear();

        for (Entity& ent : entities)
        {
            window.render(ent);
        }

        window.display();

        int frameTicks = SDL_GetTicks() - firstTick;

        if (frameTicks < 1000 / window.getRefreshRate())
        {
            SDL_Delay((1000 / window.getRefreshRate()) - frameTicks);
        }
    }

    window.destroyWindow();
    SDL_Quit();
}