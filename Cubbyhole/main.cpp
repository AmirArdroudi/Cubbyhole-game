#include "Device.h"
#include <iostream>

int main(int argc, char ** argv)
{
	Game::Device* device = new Game::Device();

	if (!device->initWindow("Cubbyhole", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0))
	{
		std::cout << "Failed to initialize SDL!! (SLD_ERROR : " << SDL_GetError()<<" )."<< std::endl;
	}
	else
	{
		SDL_Delay(2000);
		device->closeWindow();
	}

	return 0;
}