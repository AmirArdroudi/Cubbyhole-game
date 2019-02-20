#pragma once

#include <SDL.h>

#include "Device.h"

class TextureManager
{
public:
	static SDL_Texture* LoadTexture(const char* fileName, SDL_Renderer* renderer);

private:

};