#pragma once


#include "Device.h"

class Map
{
public:
	// Constructor
	Map();
	// Deconstructor
	~Map();

	void LoadMap(int array[20][25]);

	void DrawMap();
private:
	
	SDL_Rect src, dest;			// hold source and destination for rendering
	SDL_Texture* dirt;
	SDL_Texture* grass;
	SDL_Texture* water;

	int map[20][25];

};

