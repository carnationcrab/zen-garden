#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "Entity.hpp"

Entity::Entity(float p_x, float p_y, SDL_Texture* p_tx)
:x(p_x), y(p_y), tx(p_tx)
{

	// :x(p_x) member is the same as x = p_x

	currentFrame.x = 0;
	currentFrame.y = 0;
	currentFrame.w = 32;
	currentFrame.h = 32;
}

// restricted
float Entity::getX()
{
	return x;
}

float Entity::getY()
{
	return y;
}

SDL_Texture* Entity::getTx()
{
	return tx;
}

SDL_Rect Entity::getCurrentFrame()
{
	return currentFrame;
}
