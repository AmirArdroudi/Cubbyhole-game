// ---------------------------------------------------------
//
// file name : Device.cpp'
// summary : This class is created for initializing window
// Data : 12/4/2018
// Author : Amir Ardroudi
//
// ---------------------------------------------------------

#include <iostream>
#include <Windows.h>

#include "Device.h"
#include "TextureManager.h"

SDL_Texture* p_Texplayer;
SDL_Rect srcR, desR;
int count = 0;
namespace Game
{

	//! Constructor
	Device::Device() : m_pWindow(nullptr), m_pRenderer(nullptr), m_bIsRunning(true)
	{}

	//! Destructor
	Device::~Device()
	{
		m_pWindow = nullptr;
		m_pRenderer = nullptr;
	}

	// Initialize window
	void Device::InitWindow(const char*  title, int xPosWindow, int yPosWindow,
							int width, int height, bool fullscreen)
	{
		int flags = 0;

		if (fullscreen)
		{
			flags = SDL_WINDOW_FULLSCREEN;
		}

		//if subsystem initialized successfully 
		if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
		{
			std::cout << "Subsystems inizialized!" << std::endl;

			m_pWindow = SDL_CreateWindow(title, xPosWindow, yPosWindow, width, height, flags);
			if (m_pWindow)
			{
				std::cout << "Window created!" << std::endl;
			}

			m_pRenderer = SDL_CreateRenderer(m_pWindow , -1, 0);

			if (m_pRenderer)
			{
				SDL_SetRenderDrawColor(m_pRenderer, 255, 255, 255, 255);
				std::cout << "Renderer created!" << std::endl;
			}

			m_bIsRunning = true;
		}
		else
		{
			m_bIsRunning = false;
		}

		p_Texplayer = TextureManager::LoadTexture("Assets/peniser.png", m_pRenderer);
	}

	void Device::HandleEvents()
	{
		SDL_Event event;
		SDL_PollEvent(&event);

		switch (event.type)
		{
		case SDL_QUIT:
			m_bIsRunning = false;
			break;

		default:
			break; 
		}
	}

	void Device::Render()
	{
		// clear our renderer
		SDL_RenderClear(m_pRenderer);
		
		SDL_RenderCopy(m_pRenderer, p_Texplayer, NULL, &desR);

		SDL_RenderPresent(m_pRenderer);
	}
	void Device::Update()
	{
		count++;
		desR.h = 64;
		desR.w = 64;
		desR.x = count;

	}

	void Device::Clean()
	{
		SDL_DestroyWindow(m_pWindow);
		SDL_DestroyRenderer(m_pRenderer);
		SDL_Quit();

		std::cout << "game cleaned!" << std::endl;
	}

	bool Device::Running()
	{
		return m_bIsRunning;
	}

} // Game