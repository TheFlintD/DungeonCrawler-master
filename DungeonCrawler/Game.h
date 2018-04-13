#ifndef GAME_h
#define GAME_h

#include "SDL.h"
#include "SDL_image.h"
#include <iostream>

class Game {
	public:
		Game();
		~Game();

		void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
		void gameLoop();
		void handleEvents();
		void update(); // goes through all game objets and updates
		void render(); // renders game objects to screen
		void clean(); // clear the games memory after we are done
		bool running(); // lets main function know that the game should be running

	private:
		int mouseState = 0;
		int count = 0;
		bool isRunning = false;
		SDL_Window *window;
		SDL_Renderer *renderer;
};

#endif /* GAME_h */