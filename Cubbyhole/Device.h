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

		bool initWindow(const char*  title, int xPosWindow, int yPosWindow,
					int Width, int height, bool fullscreen);

		void closeWindow();


		

	private:

		SDL_Window*	  m_pWindow;
		SDL_Renderer* m_pRenderer;
		SDL_Surface*  m_pScreenSurface;

	}; // Device

} // init
