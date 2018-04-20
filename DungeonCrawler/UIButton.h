#pragma once
#include "SDL.h"

class UIButton {
public:
	UIButton(SDL_Renderer* ren, int x, int y, char* imgFile);
	~UIButton();

	void render();
	void update();
	void hover();
	void click();

private:
	int xPos;
	int yPos;

	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;
	SDL_Renderer* renderer;
};
