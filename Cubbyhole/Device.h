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
					int height, int width,  bool fullscreen);

		void CloseWindow();

		void EventsHandler();

		bool IsRunning();

		void Render();
		
		

		void DebugConsole();

		void LoadTexture();
		//SDL_GetWindowSurface* getWindowSurface();
	private:

		SDL_Window*	  m_pWindow;
		SDL_Renderer* m_pRenderer;
		bool		  m_bGameIsRunning;

		SDL_Texture* m_pTexture;
		SDL_Rect m_sourceRectangle;
		SDL_Rect m_destinationRectangle;

	}; // Device

} // game
