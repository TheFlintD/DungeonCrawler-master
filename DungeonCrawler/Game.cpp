#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "UIElements.h"
#include "Background.h"
#include <iostream>
using namespace std;

GameObject* _player, *_player2, *_player3, *_player4;
UIElements* _button1, *_button2, *_button3;
Background* _background;

bool back = false;

SDL_Rect srcR;

Game::Game() {
	init("DungeonCrawler", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);
}
Game::~Game() {
	clean();
}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {
	int flags = 0;
	if (fullscreen) {
		// SDL_WINDOW_FULLSCREEN is a flag in SDL that represents fullscreen mode
		// SDL_WINDOW_FULLSCREEN_DESKTOP is a "fake" fullscreen that takes of the size of the desktop
		// 0 is for windowed mode
		flags = SDL_WINDOW_FULLSCREEN;
	}

	// Make sure SDL initializes correctly before making any windows
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {// if 0, successfully initialized SDL subsystems
		cout << "Subsystem Initialized!..." << endl;

		// create window
		// SDL_CreateWindow() returns the window that was created or NULL on failure
		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window) {
			cout << "Window created" << endl;
		}

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			cout << "Renderer created" << endl;
			SDL_RenderClear(renderer);
		}

		isRunning = true;
	}

	_background = new Background("sprites/background.png", renderer);
	_player = new GameObject(renderer, 't', "ally", 1); // tank
	_player2 = new GameObject(renderer, 'd', "ally", 2); // dps
	_player3 = new GameObject(renderer, 's', "ally", 3); // sup
	_player4 = new GameObject(renderer, 'r', "ally", 4); // range
	_button1 = new UIElements("sprites/buttons/button1_default.png", renderer, 100, 360, 1);
	_button2 = new UIElements("sprites/buttons/button1_mouseover.png", renderer, 100, 360, 1);
	_button3 = new UIElements("sprites/buttons/button1_mousepress.png", renderer, 100, 360, 1);
}

void Game::handleEvents() {
	int x = 0;
	int y = 0;
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type) {
		// When clicking on "x" on window, this generates an event called SDL_QUIT
		// This will be picked up under event.type and will set isRunning to false
		// so when our loop checks if the game is running, it will stop it on the next loop
	case SDL_QUIT:
		isRunning = false;
		break;
	case SDL_MOUSEMOTION:
		x = event.motion.x;
		y = event.motion.y;
		if ((x > _button1->getDestRect().x) && (x < _button1->getDestRect().x + _button1->getDestRect().w) && (y > _button1->getDestRect().y) && (y < _button1->getDestRect().y + _button1->getDestRect().h)) {
			mouseState = 1;
		}
		else {
			mouseState = 0;
		}
		break;
	case SDL_MOUSEBUTTONDOWN:
		x = event.button.x;
		y = event.button.y;
		if ((x > _button1->getDestRect().x) && (x < _button1->getDestRect().x + _button1->getDestRect().w) && (y > _button1->getDestRect().y) && (y < _button1->getDestRect().y + _button1->getDestRect().h)) {
			mouseState = 2;
			cout << "Attack 1: 5 damage" << endl;
			//_player->attack();
			if (!back) {
				_background->changeBackground("sprites/background2.png");
				back = true;
			}
			else {
				_background->changeBackground("sprites/background.png");
				back = false;
			}

		}
		break;
	case SDL_MOUSEBUTTONUP:
		mouseState = 0;
		break;
	default:
		break;
	}
}

void Game::update() {
	_player->update();
	_player2->update();
	_player3->update();
	_player4->update();
	_background->update();
	_button1->update();
	_button2->update();
	_button3->update();

	srcR.h = 600;
	srcR.w = 800;
	srcR.x = 0;
	srcR.y = 0;
}

void Game::render() {
	// clear renderes buffer
	SDL_RenderClear(renderer);
	
	_background->render();
	_player->render();
	_player2->render();
	_player3->render();
	_player4->render();

	switch (mouseState) {
		case 0:
			_button1->render();
			break;
		case 1:
			_button2->render();
			break;
		case 2:
			_button3->render();
			break;
		case 3:
			break;
		default:
			break;
	}

	// add things to render
	SDL_RenderPresent(renderer);
}

void Game::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit(); // close all SDL subsystems
	cout << "Game Cleaned" << endl;
}

bool Game::running() {
	return isRunning;
}