#ifndef BUTTON_H
#define BUTTON_H

#include "SDL.h"

class Button {
	public:
		Button(int xpos, int ypos, int width, int height);
		void set_clips();
	private:
		const int CLIP_MOUSEOVER = 0;
		const int CLIP_MOUSEDEFAULT = 1;
		const int CLIP_MOUSEDOWN = 2;
		const int CLIP_MOUSEUP = 3;
		SDL_Rect box;
		SDL_Rect *clip;
		SDL_Rect clips[4];
};
#endif // !BUTTON_H
