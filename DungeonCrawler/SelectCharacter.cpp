#include "SelectCharacter.h"
#include "TextureManager.h"
#include <iostream>


SelectCharacter::SelectCharacter(SDL_Renderer* ren, GameObject* person, char type) {
	renderer = ren;
	objTexture = TextureManager::LoadTexture("", renderer);
	character = person;
	UItype = type;
	selected = false;
	placeholder = new GameObject(ren, 'p', "placeholder", 99);
}

void SelectCharacter::update() {

	srcRect.h = 105;
	srcRect.w = 105;
	ypos = 245;

	switch (character->getPos())
	{
	case 1:
		xpos = 333;
		break;
	case 2:
		xpos = 233;
		break;
	case 3:
		xpos = 133;
		break;
	case 4:
		xpos = 33;
		break;
	default:
		selected = false;
		break;
	}
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = srcRect.w;
	destRect.h = srcRect.h;
}

void SelectCharacter::hover() {
	//if(!selected)
		objTexture = TextureManager::LoadTexture("sprites/buttons/selectHover.png", renderer);
}

void SelectCharacter::click(GameObject* a) {
	if (selected) {
		character = placeholder;
		objTexture = TextureManager::LoadTexture("sprites/buttons/selectHover.png", renderer);
		selected = false;
	}
	else {
		character = a;
		objTexture = TextureManager::LoadTexture("sprites/buttons/selectClick.png", renderer);
		selected = true;
		std::cout << a->getRole() << " selected." << std::endl;
	}
	update();
}

void SelectCharacter::deselect() {
	if(!selected)
		objTexture = TextureManager::LoadTexture("", renderer);
}

void SelectCharacter::render() {
	SDL_RenderCopy(renderer, objTexture, &srcRect, &destRect);
}

SDL_Rect SelectCharacter::getDestRect() {
	return destRect;
}

void SelectCharacter::swapChar(GameObject* a) {
	GameObject* temp;
	temp = character;
	character = a;
	a = temp;
}
