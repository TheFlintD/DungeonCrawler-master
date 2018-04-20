#include "GameObject.h"
#include "TextureManager.h"
#include <iostream>
using namespace std;

GameObject::GameObject(SDL_Renderer* ren, char type, const char* role, int position) {
	renderer = ren;

	objType = type;
	characterRole = role;
	pos = position;
	status = 'a';
	switch (pos)
	{
	case 1:
		xpos = 320;
		ypos = 230;
		break;
	case 2:
		xpos = 220;
		ypos = 230;
		break;
	case 3:
		xpos = 120;
		ypos = 230;
		break;
	case 4:
		xpos = 20;
		ypos = 230;
		break;
	default:
		break;
	}
	switch (objType)
	{
		case 't'://tank
			objTexture = TextureManager::LoadTexture("sprites/allies/role_tank.png", renderer);
			maxHealth = 150;
			health = 150;
			maxEnergy = 50;
			energy = 50;
			damage = 5;
			accuracy = .6;
			crit = .25;
			resist = .4;
			initiative = 3;
			break;
		case 'd'://damage dealer
			objTexture = TextureManager::LoadTexture("sprites/allies/role_dps.png", renderer);
			maxHealth = 100;
			health = 100;
			maxEnergy = 100;
			energy = 100;
			damage = 10;
			accuracy = .8;
			crit = .35;
			resist = .25;
			initiative = 6;
			break;
		case 's'://support
			objTexture = TextureManager::LoadTexture("sprites/allies/role_sup.png", renderer);
			maxHealth = 100;
			health = 100;
			maxEnergy = 150;
			energy = 150;
			damage = 5;
			accuracy = .9;
			crit = .2;
			resist = .15;
			initiative = 8;
			break;
		case 'r':// ranged
			objTexture = TextureManager::LoadTexture("sprites/allies/role_range.png", renderer);
			maxHealth = 75;
			health = 75;
			maxEnergy = 100;
			energy = 100;
			damage = 10;
			accuracy = .9;
			crit = .35;
			resist = .15;
			initiative = 8;
			break;
		default:
			break;
	}
}

void GameObject::update() {

	switch (status)
	{
	case 'a':
		srcRect.h = 120;
		srcRect.w = 120;
		srcRect.x = 0;
		srcRect.y = 0;
		break;
	case 'd':
		objTexture = TextureManager::LoadTexture("sprites/allies/deadAlly.png", renderer);
		srcRect.h = 120;
		srcRect.w = 120;
		srcRect.x = 0;
		srcRect.y = 0;

	default:
		srcRect.h = 120;
		srcRect.w = 120;
		srcRect.x = 0;
		srcRect.y = 0;
		break;
	}

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = srcRect.w;
	destRect.h = srcRect.h;
}

SDL_Rect GameObject::getDestRect() {
	return destRect;
}

bool GameObject::checkMouse(int x, int y) {
	if ((x > this->getDestRect().x) && (x < this->getDestRect().x + this->getDestRect().w) && (this->getDestRect().y) && (y < this->getDestRect().y + this->getDestRect().h))
		return true;
	return false;
}

int GameObject::getPos() {
	return pos;
}

void GameObject::attack() {
	//enemy->health = enemy->health - damage;
	health = health - damage;
	cout << health << " / " << maxHealth << endl;
	if (health <= 0)
		status = 'd';
}

const char* GameObject::getRole() {
	return characterRole;
}

void GameObject::render() {
	SDL_RenderCopy(renderer, objTexture, &srcRect, &destRect);
}