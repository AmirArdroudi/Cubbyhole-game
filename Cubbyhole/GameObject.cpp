// -------------------------------------------------------
//
// file name : Device.h'
// summary : 
// Data : 19/2/2019
// Author : Amir Ardroudi 
//
// ---------------------------------------------------------

#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char* textureSheet, int x, int y)
{
	m_pObjectTexture = TextureManager::LoadTexture(textureSheet);

	xPosition = x;
	yPosition = y;
}

void GameObject::Update()
{
	//testing movement
	xPosition++;
	yPosition++;

	m_srcRect.x = 0;
	m_srcRect.y = 0;
	m_srcRect.w = 400;
	m_srcRect.h = 400;
	
	m_destRect.x = xPosition;
	m_destRect.y = yPosition;
	m_destRect.w = 64;
	m_destRect.h = 64;

}

void GameObject::Render()
{
	SDL_RenderCopy(Game::Device::m_pRenderer, m_pObjectTexture, &m_srcRect, &m_destRect);
}