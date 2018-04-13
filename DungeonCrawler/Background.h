#pragma once
#include "Game.h"

class Background {
public:
	Background(const char* textureSheet, SDL_Renderer* ren);
	~Background();

	void update();
	void render();
	void changeBackground(const char* textureSheet);

	SDL_Rect getDestRect();
private:
	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;
	SDL_Renderer* renderer;
};