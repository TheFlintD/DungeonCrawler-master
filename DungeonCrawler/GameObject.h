#pragma once
#include "Game.h"

class GameObject {
	public:
		GameObject(SDL_Renderer* ren, char type, const char* role, int pos);
		~GameObject();

		void update();
		void attack();
		void render();
		const char* getRole();
		int getPos();


		int health;
		int energy;
		int damage;
		char status;

		SDL_Rect getDestRect();
		bool checkMouse(int x, int y);

	private:
		int xpos;
		int ypos;
		char objType;

		const char* characterRole;
		int pos;

		int maxHealth;
		int maxEnergy;

		double accuracy;
		double crit;
		double resist;

		int initiative;

		SDL_Texture* objTexture;
		SDL_Rect srcRect, destRect;
		SDL_Renderer* renderer;
};