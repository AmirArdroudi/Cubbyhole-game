// ---------------------------------------------------------
//
// file name : Device.cpp'
// summary : This class is created for initializing window
// Data : 12/4/2018
// 
// ---------------------------------------------------------

#include <iostream>
#include "Device.h"

namespace Game
{

	//! Constructor
	Device::Device() : m_pWindow(nullptr), m_pRenderer(nullptr), m_bGameIsRunning(true)
	{}

	//! Destructor
	Device::~Device()
	{
		m_pWindow = nullptr;
		m_pRenderer = nullptr;
	}

	// Initialize window
	bool Device::InitWindow(const char* title, int xPosWindow, int yPosWindow,
					int width, int height, bool fullscreen)
	{
		bool success = true;

		// Initialize SDL
		if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
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

			if (m_pWindow != NULL)
			{
				m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
			}
			else
			{
				std::cout << "Could not initialize! SLD_ERROR : " << SDL_GetError();
				success = false;
			}
		}
		else
		{
			std::cout << "Could not initialize! SLD_ERROR : " << SDL_GetError();
			success = false;
			
		}
		
		return success;
		
	} // initWindow

	void Device::Render()
	{
		// color the screen to purple
		SDL_SetRenderDrawColor(m_pRenderer, 200, 0, 255, 255);
		// clear the window
		SDL_RenderClear(m_pRenderer);
		// show the window
		SDL_RenderPresent(m_pRenderer);
	}

	void Device::CloseWindow()
	{
		SDL_DestroyWindow(m_pWindow);
		m_pWindow = NULL;
		SDL_Quit();
	} // closeWindow

	void Device::EventsHandler()
	{
		SDL_Event event;
		if (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
				case SDL_QUIT:
					m_bGameIsRunning = false;
					break;
			}
		}
	}

	bool Device::Running()
	{
		return m_bGameIsRunning;
	}

} // Game