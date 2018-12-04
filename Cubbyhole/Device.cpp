#include <iostream>

#include "Device.h"

namespace Game
{
	//! Constructor
	Device::Device() : m_pWindow(nullptr), m_pRenderer(nullptr)
	{}

	// Initialize window
	void Device::initWindow(const char* title, int xPosWindow, int yPosWindow,
					int width, int height, bool fullscreen)
	{
		SDL_Init(SDL_INIT_VIDEO);

		if (fullscreen)
		{
			m_pWindow = SDL_CreateWindow(title, xPosWindow, yPosWindow, width, height, SDL_WINDOW_FULLSCREEN);
		}
		else
		{
			m_pWindow = SDL_CreateWindow(title, xPosWindow, yPosWindow, width, height, 0);
		}
		if (m_pWindow == NULL)
		{
			printf("Couldn't create window : %s\n", SDL_GetError());
		}
		
	}

} // Game