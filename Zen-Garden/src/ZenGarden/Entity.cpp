#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <cassert>

#include "Entity.h"
#include "Math.h"

Entity::Entity(Vector2f p_pos, SDL_Texture* p_tx)
    :tx(p_tx), pos(p_pos)
{
    assert(p_tx && "Entity Constructor: Null texture passed to Entity constructor!");

    // Set current frame
    currentFrame.x = 0;
    currentFrame.y = 0;
    currentFrame.w = 32;
    currentFrame.h = 32;
}

// Restricted
SDL_Texture* Entity::getTx()
{
    assert(tx && "Entity::getTx(): Null texture in Entity::getTx!");

    return tx;
}

SDL_Rect Entity::getCurrentFrame()
{
    assert(currentFrame.w >= 0 && currentFrame.h >= 0 && "Entity::getCurrentFrame(): Negative width or height in Entity::getCurrentFrame!");

    return currentFrame;
}