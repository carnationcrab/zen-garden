#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>

#include "RenderWindow.hpp"
#include "Entity.hpp"
#include "Utils.hpp"

int main(int argc, char* args[]) 
{
	// load SDL
	if (SDL_Init(SDL_INIT_VIDEO) > 0) 
	{
		std::cout << "SDL_Init failed to initialize! ERROR:" << SDL_GetError() << std::endl;
	}

	if (!(IMG_Init(IMG_INIT_PNG)))
	{
		std::cout << "IMG_Init failed to initialize! ERROR:" << SDL_GetError() << std::endl;
	}

	// render window
	RenderWindow  window("ZEN_GARDEN v1.0", 1280, 720);

	// render textures
	SDL_Texture* tx_grass = window.loadTexture("res/gfx/ground_grass_1.png");

	// std::vector<Entity> entities =
	// {
	// 	Entity(Vector2f(0, 0), tx_grass),
	// 	Entity(Vector2f(30, 0), tx_grass),
	// 	Entity(Vector2f(30, 30), tx_grass),
	// };

	std::vector<Entity> entities;

	// Puts the entities directly into the vector
	entities.emplace_back(Vector2f(0, 0), tx_grass);
	entities.emplace_back(Vector2f(30, 0), tx_grass);
	entities.emplace_back(Vector2f(30, 30), tx_grass);

	bool gameRunning = true;

	SDL_Event event;

	// timestepping (or the elapsed time in the game)
	const float timeStep = 0.01f;
	float accumulator = 0.0f;
	float currentTime = utils::getTimeInSeconds();

	while (gameRunning)
	{
		int firstTick = SDL_GetTicks();

		float newTime = utils::getTimeInSeconds();
		float frameTime = newTime - currentTime;

		// The game needs to equal a timestep to advance.
		currentTime = newTime;
		accumulator += frameTime;

		while (accumulator >= timeStep)
		{
			// hack to keep game running
			while (SDL_PollEvent(&event))
			{
				if (event.type == SDL_QUIT)
					gameRunning = false;
			}

			accumulator -= timeStep;
		}

		// for linear interpolation
		// const float alpha = accumulator / timeStep;

		window.clear();

		// renders all entities -- is this slower than a normal for loop?
		for (Entity& ent : entities)
		{
			window.render(ent); 
		}

		// std::cout << utils::getTimeInSeconds() << std::endl;

		window.display();

		// refresh rate limiter - if game runs too fast, slow down.
		int frameTicks = SDL_GetTicks() - firstTick;
		// if frameticks < minimum
		if (frameTicks < 1000 / window.getRefreshRate())
		{
			SDL_Delay(
				(1000 / window.getRefreshRate()) - frameTicks);
		}

	} 

	// on quit
	window.destroyWindow();
	SDL_Quit();
	
	// SDL requires return 0
	return 0;
}