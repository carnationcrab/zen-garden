#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Entity
{
public:
	Entity(float p_x, float p_y, SDL_Texture* p_tx);
	float getX();
	float getY();
	SDL_Texture* getTx();
	SDL_Rect getCurrentFrame();
private:
	// todo put this in a vector class
	float x, y;
	SDL_Rect currentFrame;
	SDL_Texture* tx;
};