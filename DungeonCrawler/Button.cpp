#include "Button.h"
#include "SDL.h"
#include "Graphics.h"

Button::Button(int xpos, int ypos, int width, int height) {
	set_clips();

	box.x = xpos;
	box.y = ypos;
	box.w = width;
	box.h = height;

	clip = &clips[CLIP_MOUSEDEFAULT];
}

void Button::set_clips() {
	clips[CLIP_MOUSEOVER].x = 0;
	clips[CLIP_MOUSEOVER].y = 0;
	clips[CLIP_MOUSEOVER].w = 100;
	clips[CLIP_MOUSEOVER].h = 30;

	clips[CLIP_MOUSEDEFAULT].x = 0;
	clips[CLIP_MOUSEDEFAULT].y = 0;
	clips[CLIP_MOUSEDEFAULT].w = 100;
	clips[CLIP_MOUSEDEFAULT].h = 30;

	clips[CLIP_MOUSEDOWN].x = 0;
	clips[CLIP_MOUSEDOWN].y = 0;
	clips[CLIP_MOUSEDOWN].w = 100;
	clips[CLIP_MOUSEDOWN].h = 30;

	clips[CLIP_MOUSEUP].x = 0;
	clips[CLIP_MOUSEUP].y = 0;
	clips[CLIP_MOUSEUP].w = 100;
	clips[CLIP_MOUSEUP].h = 30;
}