#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <string>

#include "Entity.h"

class RenderWindow
{
public:
	RenderWindow(const char* p_title, int p_width, int p_height);
	SDL_Texture* loadTexture(std::string p_filePath);

	int getRefreshRate();

	void clear();
	void render(Entity& p_entity);
	void display();

	void destroyWindow();
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	int refreshRate;
};
