#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "RenderWindow.hpp"
#include "Entity.hpp"

// member initialization :window(NULL), renderer(NULL)
RenderWindow::RenderWindow(const char* p_title, int p_width, int p_height)
	:window(NULL), renderer(NULL), refreshRate(60)
{
	window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_width, p_height, SDL_WINDOW_SHOWN);

	if (window == NULL)
	{
		std::cout << "SDL_CreateWindow failed to load window! ERROR:" << SDL_GetError() << std::endl;
	}

	// creates renderer. -1 is a hack to choose first graphics driver that satisfies all requirements
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

SDL_Texture* RenderWindow::loadTexture(const char* p_filePath)
{
	SDL_Texture* texture = NULL;

	texture = IMG_LoadTexture(renderer, p_filePath);

	if (texture == NULL)
	{
		std::cout << "SDL_Texture failed to load textures! ERROR:" << SDL_GetError() << std::endl;
	}

	return texture;
}

// gopher time. (Not necessary and could be replaced with vsync)
int RenderWindow::getRefreshRate()
{
	int displayIndex = SDL_GetWindowDisplayIndex(window);

	SDL_DisplayMode mode;

	SDL_GetDisplayMode(displayIndex, 0, &mode);

	return mode.refresh_rate;
}

void RenderWindow::clear()
{
	SDL_RenderClear(renderer);
}

void RenderWindow::render(Entity& p_entity)
{
	SDL_Rect src;
	src.x = p_entity.getCurrentFrame().x;
	src.y = p_entity.getCurrentFrame().y;
	src.w = p_entity.getCurrentFrame().w;
	src.h = p_entity.getCurrentFrame().h;

	SDL_Rect dst;
	dst.x = p_entity.getPos().x * 4;
	dst.y = p_entity.getPos().y * 4;
	dst.w = p_entity.getCurrentFrame().w * 4;
	dst.h = p_entity.getCurrentFrame().h * 4;

	SDL_RenderCopy(renderer, p_entity.getTx(), &src, &dst);
}

void RenderWindow::display()
{
	SDL_RenderPresent(renderer);
}

// on quit
void RenderWindow::destroyWindow()
{
	SDL_DestroyWindow(window);
}