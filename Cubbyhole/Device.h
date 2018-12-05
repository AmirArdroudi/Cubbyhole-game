// ---------------------------------------------------------
//
// file name : Device.h'
// summary : This class is created for initializing window
// Data : 12/4/2018
// 
// ---------------------------------------------------------

#pragma once

#include <SDL.h>

namespace Game
{
	class Device
	{

	public:
		//! Constructor
		Device();

		//! Destructor
		~Device();

		bool InitWindow(const char*  title, int xPosWindow, int yPosWindow,
					int Width, int height, bool fullscreen);

		void CloseWindow();

		void EventsHandler();

		bool Running();

		void Render();
		
		//SDL_GetWindowSurface* getWindowSurface();
	private:

		SDL_Window*	  m_pWindow;
		SDL_Renderer* m_pRenderer;
		SDL_Surface*  m_pScreenSurface;
		bool		  m_bGameIsRunning;

	}; // Device

} // game
