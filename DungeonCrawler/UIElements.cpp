#include "UIElements.h"
#include "TextureManager.h"
#include <iostream>


UIElements::UIElements(const char* textureSheet, SDL_Renderer* ren, int x, int y, int type) {
	renderer = ren;
	objTexture = TextureManager::LoadTexture(textureSheet, renderer);
	xpos = x;
	ypos = y;
	UItype = type;
}

void UIElements::update() {

	srcRect.h = 30;
	srcRect.w = 100;
	srcRect.x = 0;
	srcRect.y = 0;
	
	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = srcRect.w;
	destRect.h = srcRect.h;
}

void UIElements::render() {
	SDL_RenderCopy(renderer, objTexture, &srcRect, &destRect);
}

SDL_Rect UIElements::getDestRect() {
	return destRect;
}

void UIElements::attackChar(GameObject* a, GameObject* b) {
	if (a->getRole() == b->getRole()) {
		std::cout << "Can't attack your ally!" << std::endl;
	}
	else if (b->health <= 0) {
		std::cout << "Enemy is already dead." << std::endl;
	}
	else {
		b->health = b->health - a->damage;
		std::cout << "Attack successful \n Enemy has taken " << a->damage << " damage.\n " << b->health << " remaining." << std::endl;
	}
}