#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "RenderWindow.hpp"
#include "Entity.hpp"

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
	RenderWindow  window("GAME v1.0", 1280, 720);

	// render textures
	SDL_Texture* tx_grass = window.loadTexture("res/gfx/ground_grass_1.png");

	Entity entity0(50, 50, tx_grass);
	Entity entity1(50, 50, tx_grass);

	bool gameRunning = true;
	SDL_Event event;

	while (gameRunning)
	{
	// hack to keep game running
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				gameRunning = false;
		}

		window.clear();

		window.render(entity0);
		window.display();
	}

	// on quit
	window.destroyWindow();
	SDL_Quit();
	
	// SDL requires return 0
	return 0;
}