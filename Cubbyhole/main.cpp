#include <Windows.h>
#include <iostream>

#include "Device.h"
// page 34
int main(int argc, char ** argv)
{

	Game::Device* device = new Game::Device();

	//set Debugging console
	device->DebugConsole();

	if (device->InitWindow("Cubbyhole", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, false))
	{
		while (device->IsRunning())
		{
			device->EventsHandler();
			device->Render();
		}
	}
	else
	{
		std::cout << "Failed to initialize SDL!! (SLD_ERROR : " << SDL_GetError() << " )." << std::endl;
		return 1;
		
	}
	
	
	device->CloseWindow();
	delete device;

	return 0;
}