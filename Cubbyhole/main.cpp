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
	Game::Device* device = new Game::Device();
	
	device->InitWindow("Cubbyhole", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);

	while (device->Running())
	{
		
		device->HandleEvents();
		device->Update();
		device->Render();
	}
	
	device->Clean();
	delete device;

	return 0;
}