#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "Entity.hpp"

Entity::Entity(Vector2f p_pos, SDL_Texture* p_tx)
:pos(p_pos), tx(p_tx)
{

	// :x(p_x) member is the same as x = p_x

	// set current frame
	currentFrame.x = 0;
	currentFrame.y = 0;
	currentFrame.w = 32;
	currentFrame.h = 32;
}

// restricted
SDL_Texture* Entity::getTx()
{
	return tx;
}

SDL_Rect Entity::getCurrentFrame()
{
	return currentFrame;
}
