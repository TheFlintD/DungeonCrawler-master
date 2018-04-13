#include "Background.h"
#include "TextureManager.h"

Background::Background(const char* textureSheet, SDL_Renderer* ren) {
	renderer = ren;
	objTexture = TextureManager::LoadTexture(textureSheet, renderer);
}

void Background::update() {

	srcRect.h = 600;
	srcRect.w = 800;
	srcRect.x = 0;
	srcRect.y = 0;
	destRect.w = srcRect.w;
	destRect.h = srcRect.h;

}

void Background::changeBackground(const char* textureSheet) {
	objTexture = TextureManager::LoadTexture(textureSheet, renderer);
}

void Background::render() {
	SDL_RenderCopy(renderer, objTexture, &srcRect, &destRect);
}

SDL_Rect Background::getDestRect() {
	return destRect;
}