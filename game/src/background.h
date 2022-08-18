#pragma once
#include "raylib.h"
class background
{
public:
	void init();
	float scrollingSpeed;
	Texture2D image;
	void updateBackground();
	void drawBackground();
};
