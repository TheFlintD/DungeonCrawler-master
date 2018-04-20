#pragma once
#include "Game.h"
#include "GameObject.h"

class UIElements {
	public:
		UIElements(const char* textureSheet, SDL_Renderer* ren, int x, int y, int type);
		~UIElements();

		void update();
		void render();
		void swapChar(GameObject a, GameObject b);
		void attackChar(GameObject* a, GameObject* b);


		SDL_Rect getDestRect();
	private:
		int xpos;
		int ypos;
		int UItype;
		SDL_Texture* objTexture;
		SDL_Rect srcRect, destRect;
		SDL_Renderer* renderer;
};