#include "MouseEvents.h"
#include "GameObject.h"
#include <iostream>


MouseEvents::MouseEvents() {
	x = 0;
	y = 0;
}

void MouseEvents::enactAction() {
	SDL_PollEvent(&event);
	switch (event.type) {
	case SDL_QUIT:
		isRunning = false;
		break;
	case SDL_MOUSEMOTION:
		x = event.motion.x;
		y = event.motion.y;
		if (()) {
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
			_player->attack();

		}
		break;
	case SDL_MOUSEBUTTONUP:
		mouseState = 0;
		break;
	default:
		break;
	}
}

