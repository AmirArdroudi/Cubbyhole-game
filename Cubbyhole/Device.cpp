// ---------------------------------------------------------
//
// file name : Device.cpp'
// summary : This class is created for initializing window
// Data : 12/4/2018
// 
// ---------------------------------------------------------

#include <iostream>
#include <Windows.h>

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
						int height, int width, bool fullscreen)
	{
		int flags = 0;
		if (fullscreen)
		{
			flags = SDL_WINDOW_FULLSCREEN;
		}

		if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
		{
			std::cout << "SDL init success\n";
			//init window
			m_pWindow = SDL_CreateWindow(title, xPosWindow, yPosWindow,
				height, width, fullscreen);
			
			if (m_pWindow != NULL)
			{
				std::cout << "Window creation Success\n";
				m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

				if (m_pRenderer != NULL)
				{
					std::cout << "renderer creation Success\n";
				}
				else
				{
					std::cout << "renderer init fail\n";
					return false;
				}
			}
			else
			{
				std::cout << "Window init fail\n";
				return false;
			}
		}
		else
		{
			std::cout << "SDL init fail\n";
			return false;
		}
		std::cout << "init success\n";

		Device::LoadTexture();

		return true;
		
	} // initWindow

	void Device::Render()
	{
		// color the screen to purple
		SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);
		// clear the window
		SDL_RenderClear(m_pRenderer);
		
		SDL_RenderCopy(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_sourceRectangle);
		// show the window
		SDL_RenderPresent(m_pRenderer);
	}

	void Device::CloseWindow()
	{
		std::cout << "cleaning game\n";
		// Destroy window
		SDL_DestroyWindow(m_pWindow);
		m_pWindow = NULL;

		SDL_DestroyRenderer(m_pRenderer);
		m_pRenderer = NULL;

		SDL_Quit();
	} // CloseWindow

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
				default:
					break;

			}
		}
	} // EventHandler

	bool Device::IsRunning()
	{
		return m_bGameIsRunning;
	}

	void Device::DebugConsole()
	{
		FILE *stream;
		AllocConsole();
		freopen_s(&stream, "CON", "w", stdout);
	}
	
	void Device::LoadTexture()
	{
		SDL_Surface* pTempSurface = SDL_LoadBMP("Assets/circle.bmp");
		m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);
		SDL_FreeSurface(pTempSurface);

		SDL_QueryTexture(m_pTexture, NULL, NULL, &m_sourceRectangle.w, &m_sourceRectangle.h);
		m_destinationRectangle.x = m_sourceRectangle.x = 0;
		m_destinationRectangle.y = m_sourceRectangle.y = 0;
		m_destinationRectangle.w = m_sourceRectangle.w;
		m_destinationRectangle.h = m_sourceRectangle.h;
		m_sourceRectangle.w = 50;
		m_sourceRectangle.h = 50;

	}
} // Game