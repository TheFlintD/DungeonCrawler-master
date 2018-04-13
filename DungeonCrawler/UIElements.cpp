#include "UIElements.h"
#include "TextureManager.h"

UIElements::UIElements(const char* textureSheet, SDL_Renderer* ren, int x, int y, int type) {
	renderer = ren;
	objTexture = TextureManager::LoadTexture(textureSheet, renderer);
	xpos = x;
	ypos = y;
	UItype = type;
}

void UIElements::update() {

	switch (UItype)
	{
		case 0:
			srcRect.h = 600;
			srcRect.w = 800;
			srcRect.x = 0;
			srcRect.y = 0;
			break;
		case 1:
			srcRect.h = 30;
			srcRect.w = 100;
			srcRect.x = 0;
			srcRect.y = 0;
			break;
		default:
			break;
	}

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