#include <iostream>
#include "Device.h"

namespace Game
{

	//! Constructor
	Device::Device() : m_pWindow(nullptr), m_pRenderer(nullptr)
	{}

	//! Destructor
	Device::~Device()
	{
		m_pWindow = nullptr;
		m_pRenderer = nullptr;
	}

	// Initialize window
	bool Device::initWindow(const char* title, int xPosWindow, int yPosWindow,
					int width, int height, bool fullscreen)
	{
		bool success = true;

		// Initialize SDL
		if (SDL_Init(SDL_INIT_VIDEO) < 0)
		{
			std::cout << "Could not initialize! SLD_ERROR : " << SDL_GetError();
			success = false;
		}
		else
		{
			// Create window
			if (fullscreen)
			{
				m_pWindow = SDL_CreateWindow(title, xPosWindow, yPosWindow,
								width, height, SDL_WINDOW_FULLSCREEN);
			}
			else
			{
				m_pWindow = SDL_CreateWindow(title, xPosWindow, yPosWindow,
								width, height, 0);
			}
			if (m_pWindow == NULL)
			{
				std::cout << "Could not initialize! SLD_ERROR : " << SDL_GetError();
				success = false;
			}
		}
		
		return success;
		
	}

	//
	void Device::closeWindow()
	{
		// Destroy window
		SDL_DestroyWindow(m_pWindow);
		// ??????????????? Is it fine calling destructor from here ??????????????? 
		Device::~Device();
		SDL_Quit();
	}

} // Game