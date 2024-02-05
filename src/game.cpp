#include "Game.hpp"

Game::Game() 
:window("ZEN_GARDEN v1.0", 1280, 720), gameRunning(true)
{
    SDL_Texture* tx_grass = window.loadTexture("res/gfx/ground_grass_1.png");

    entities.emplace_back(Vector2f(0, 0), tx_grass);
    entities.emplace_back(Vector2f(30, 0), tx_grass);
    entities.emplace_back(Vector2f(30, 30), tx_grass);
}

void Game::run()
{
    const float timeStep = 0.01f;
    float accumulator = 0.0f;
    float currentTime = utils::TimeInSeconds();

    SDL_Event event;

    while (gameRunning)
    {
        int firstTick = SDL_GetTicks();

        float newTime = utils::TimeInSeconds();
        float frameTime = newTime - currentTime;

        currentTime = newTime;
        accumulator += frameTime;

        while (accumulator >= timeStep)
        {
            while (SDL_PollEvent(&event))
            {
                if (event.type == SDL_QUIT)
                    gameRunning = false;
            }

            // movement logic

            accumulator -= timeStep;
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