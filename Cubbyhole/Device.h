#pragma once

#include <SDL.h>
#include <string>

namespace Game
{
	class Device
	{

	public:
		//! Constructor
		Device();

		//! Destructor
		~Device();

		void initWindow(const char*  title, int xPosWindow, int yPosWindow,
					int Width, int height, bool fullscreen);

	private:

		SDL_Window* m_pWindow;
		SDL_Renderer* m_pRenderer;

	}; // Device

} // init
