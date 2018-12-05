#include "Device.h"
#include <iostream>

int main(int argc, char ** argv)
{
	Game::Device* device = new Game::Device();


	if (!device->InitWindow("Cubbyhole", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0))
	{
		std::cout << "Failed to initialize SDL!! (SLD_ERROR : " << SDL_GetError()<<" )."<< std::endl;
		return 1;
	}
	else
	{
		// Game loop
		while (device->Running())
		{
			device->Render();
			device->EventsHandler();
		}

	}
	
	device->CloseWindow();

	delete device;

	return 0;
}