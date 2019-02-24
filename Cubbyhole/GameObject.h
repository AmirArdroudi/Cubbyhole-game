// ---------------------------------------------------------
//
// file name : Device.h'
// summary : 
// Data : 19/2/2019
// Author : Amir Ardroudi 
//
// ---------------------------------------------------------

#pragma once

#include "Device.h"

class GameObject
{

public:
	//constructor
	GameObject(const char* textureSheet, int x, int y);
	//destructor
	~GameObject();

	void Update();
	void Render();
private:
	
	int xPosition;
	int yPosition;

	SDL_Texture* m_pObjectTexture;
	SDL_Rect m_srcRect, m_destRect;

};