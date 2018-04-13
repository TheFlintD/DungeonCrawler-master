#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "SDL.h"
#include "SDL_image.h"
#include <string>
struct SDL_Window;
struct SDL_Renderer;

class Graphics {
	public:
		Graphics();
		~Graphics();
		void WindowElements();
	private:
		SDL_Window *window;
		SDL_Renderer *renderer;
		SDL_Surface *buttonSheet = NULL;
		SDL_Texture *_button = NULL;
};

#endif