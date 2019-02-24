// ---------------------------------------------------------
//
// file name : Device.h'
// summary : 
// Data : 19/2/2018
// Author : Amir Ardroudi 
//
// ---------------------------------------------------------
#include "TextureManager.h"
#include "Device.h"
 
SDL_Texture* TextureManager::LoadTexture(const char* fileName)
{
	SDL_Surface* tempSurface = IMG_Load(fileName);
	SDL_Texture* pTexture = SDL_CreateTextureFromSurface(Game::Device::m_pRenderer, tempSurface);
	SDL_FreeSurface(tempSurface);

	return pTexture;
}

void TextureManager::Draw(SDL_Texture* texture, SDL_Rect src, SDL_Rect dest)
{
	SDL_RenderCopy(Game::Device::m_pRenderer, texture, &src, &dest);

}