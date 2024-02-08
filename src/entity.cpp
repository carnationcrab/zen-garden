#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <cassert>

#include "Entity.hpp"

Entity::Entity(Vector2f p_pos, SDL_Texture* p_tx)
:tx(p_tx), pos(p_pos)
{
    assert(p_tx && "Null texture passed to Entity constructor!");

    // Set current frame
    currentFrame.x = 0;
    currentFrame.y = 0;
    currentFrame.w = 32;
    currentFrame.h = 32;
}

// Restricted
SDL_Texture* Entity::getTx()
{
    assert(tx && "Null texture in Entity::getTx!");

    return tx;
}

SDL_Rect Entity::getCurrentFrame()
{
    assert(currentFrame.w >= 0 && currentFrame.h >= 0 && "Negative width or height in Entity::getCurrentFrame!");

    return currentFrame;
}