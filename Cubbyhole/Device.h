// ---------------------------------------------------------
//
// file name : Device.h'
// summary : This class is created for initializing window
// Data : 12/4/2018
// Author : Amir Ardroudi 
//
// ---------------------------------------------------------

#pragma once

#include <SDL.h>
#include <SDL_image.h>

namespace Game
{
	class Device
	{

	public:
		//! Constructor
		Device();

		//! Destructor
		~Device();

		void InitWindow(const char*  title, int xPosWindow, int yPosWindow,
					int width, int height,  bool fullscreen);

		void Update();

		void Render();

		void Clean();

		void HandleEvents();

		bool Running();

	private:

		SDL_Window*	  m_pWindow;
		SDL_Renderer* m_pRenderer;
		bool		  m_bIsRunning;

	}; // Device

} // game
