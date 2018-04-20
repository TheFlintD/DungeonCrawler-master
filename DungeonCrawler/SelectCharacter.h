#pragma once
#include "Game.h"
#include "GameObject.h"

class SelectCharacter {
public:
	SelectCharacter(SDL_Renderer* ren, GameObject* person, char type);
	~SelectCharacter();

	void update();
	void render();
	void click(GameObject* a);
	void swapChar(GameObject* a);
	void attackChar(GameObject* a, GameObject* b);
	void hover();
	void deselect();
	bool selected;
	GameObject* character;
	GameObject* placeholder;

	SDL_Rect getDestRect();
private:
	int xpos;
	int ypos;
	int UItype;

	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;
	SDL_Renderer* renderer;
};
