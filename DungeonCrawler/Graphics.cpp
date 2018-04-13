#include "SDL.h"
#include "SDL_image.h"
#include "Graphics.h"
#include "Button.h"

Graphics::Graphics() {
	SDL_CreateWindowAndRenderer(800, 600, 0, &window, &renderer);
	SDL_SetWindowTitle(window, "Dungeon Crawler");

	buttonSheet = IMG_Load("sprites/button1_default.png");
	_button = SDL_CreateTextureFromSurface(renderer, buttonSheet);
	SDL_FreeSurface(buttonSheet);

	WindowElements();
}

Graphics::~Graphics() {
	SDL_DestroyWindow(window);
}

void Graphics::WindowElements() {
	SDL_RenderCopy(renderer, _button, NULL, NULL);
}
