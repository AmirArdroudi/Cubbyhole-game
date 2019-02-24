// ---------------------------------------------------------
//
// file name : main.cpp'
// summary : 
// Data : 12/4/2018
// Author : Amir Ardroudi
//
// ---------------------------------------------------------

#include <Windows.h>
#include <iostream>

#include "Device.h"

int main(int argc, char ** argv)
{	
	const int FPS = 60;

	// max time we have between frames
	const int frameDelay = 1000 / FPS;
	// game running time
	Uint32 frameStart;
	// frame time
	int frameTime;


	Game::Device* device = new Game::Device();
	
	device->InitWindow("Cubbyhole", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 640, false);

	while (device->Running())
	{
		// miliseconds when we first initialize SDL
		frameStart = SDL_GetTicks();

		device->HandleEvents();
		device->Update();
		device->Render();

		// how long takes to handleing and update and then rendering our objects
		frameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}
	}
	
	device->Clean();
	delete device;

	return 0;
}