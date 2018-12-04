#include "Device.h"
#include <iostream>
#include <SDL.h>

int main(int argc, char ** argv)
{
	Game::Device* game = new Game::Device();

	game->initWindow("Cubbyhole", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);

	SDL_Delay(2000);

	return 0;
}