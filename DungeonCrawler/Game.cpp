#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "UIElements.h"
#include "Background.h"
#include "SelectCharacter.h"
#include <iostream>
using namespace std;

GameObject* _player, *_player2, *_player3, *_player4, *_selected;

UIElements* _button1, *_button2, *_button3;
Background* _background;
SelectCharacter* _select, *_select2;


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
	_select = new SelectCharacter(renderer, _player, 'a');
	_select2 = new SelectCharacter(renderer, _player, 'a');
}

void Game::handleEvents() {
	int x = 0;
	int y = 0;
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type) {

	case SDL_QUIT:
		isRunning = false;
		break;
	case SDL_MOUSEMOTION:
		x = event.motion.x;
		y = event.motion.y;
		if (_player->checkMouse(x,y)) {
			if (!_select->selected) {
				_select->character = _player;
				_select->hover();
			}
			else {
				_select2->character = _player;
				_select2->hover();
			}
			mouseState = 1;
		}
		else if (_player2->checkMouse(x,y)) {
			if(!_select->selected) {
				_select->character = _player2;
				_select->hover();
			}
		else {
				_select2->character = _player2;
				_select2->hover();
			}
			mouseState = 1;
		}
		else if (_player3->checkMouse(x, y)) {
			if(!_select->selected) {
				_select->character = _player3;
				_select->hover();
			}
			else {
				_select2->character = _player3;
				_select2->hover();
			}
			mouseState = 1;
		}
		else if (_player4->checkMouse(x, y)) {
			if(!_select->selected) {
				_select->character = _player4;
				_select->hover();
			}
			else {
				_select2->character = _player4;
				_select2->hover();
			}
			mouseState = 1;
		}
		else {
			_select->deselect();
			mouseState = 0;
		}
		break;
	case SDL_MOUSEBUTTONDOWN:
		x = event.button.x;
		y = event.button.y;
		if (_player->checkMouse(x,y)) {
			_select->click(_player);
			mouseState = 2;
		}
		else if (_player2->checkMouse(x, y)) {
			_select->click(_player2);
			mouseState = 2;
		}
		else if (_player3->checkMouse(x, y)) {
			_select->click(_player3);
			mouseState = 2;
		}
		else if (_player4->checkMouse(x, y)) {
			_select->click(_player4);
			mouseState = 2;
		}
		else {
			_select->deselect();
			mouseState = 0;
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
	if(!_select->selected)
		_select->update();
	if (!_select2->selected)
		_select2->update();

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
			_select->render();
			break;
		case 1:
			_select->render();
			break;
		case 2:
			_select->render();
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