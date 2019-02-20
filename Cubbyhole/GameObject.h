#pragma once

#include "Device.h"

class GameObject
{

public:
	//constructor
	GameObject(const char* textureSheet, SDL_Renderer* renderer, int x, int y);
	//destructor
	~GameObject();

	void Update();
	void Render();
private:
	
	int xPosition;
	int yPosition;

	SDL_Texture* m_pObjectTexture;
	SDL_Rect m_srcRect, m_destRect;
	SDL_Renderer* m_pRenderer;
};