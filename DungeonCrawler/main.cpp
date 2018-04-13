#include "Game.h"
#include "SDL.h"

int main(int argc, char* argv[]) {
	const int FPS = 60;
	const int frameDelay = 1000 / FPS;

	Uint32 elapsedTime;
	int frameTime;

	Game *game = new Game();

	while (game->running()) {

		elapsedTime = SDL_GetTicks();

		game->handleEvents();
		game->update();
		game->render();

		frameTime = SDL_GetTicks() - elapsedTime;

		if (frameDelay > frameTime) {
			SDL_Delay(frameDelay - frameTime);
		}
	}

	game->clean();

	return 0;
}