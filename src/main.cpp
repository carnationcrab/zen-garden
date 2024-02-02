#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "RenderWindow.hpp"

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

	// hack to keep game running
	bool gameRunning = true;
	SDL_Event event;

	while (gameRunning)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				gameRunning = false;
		}
	}

	// on quit
	window.cleanUp();
	SDL_Quit();
	
	// SDL requires return 0
	return 0;
}