#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <Math.hpp>

class Entity
{
public:
	Entity(Vector2f p_pos, SDL_Texture* p_tx);
	Vector2f& getPos()
	{
		return pos;
	}
	SDL_Texture* getTx();
	SDL_Rect getCurrentFrame();
private:
	SDL_Texture* tx;
	Vector2f pos;
	SDL_Rect currentFrame;
};