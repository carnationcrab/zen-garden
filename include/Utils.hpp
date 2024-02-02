#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

namespace utils
{
	float getTimeInSeconds()
	{
		float t = SDL_GetTicks();

		t *= 0.001f;

		return t;
	}
}