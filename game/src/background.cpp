#include "background.h"



// init background 
void background::init()
{
	scrollingSpeed = 0.0f;
	image = LoadTexture("game/src/src/space.png");
}

// update background per frame
void background::updateBackground()
{
	scrollingSpeed -= 0.5f;
	if (scrollingSpeed <=-image.width*2)
	{
		scrollingSpeed = 0;
	}
}

// draw background per frame 
void background::drawBackground()
{
	DrawTextureEx(image, Vector2 { scrollingSpeed, 10 }, 0.0f, 2.0f, WHITE);
	DrawTextureEx(image, Vector2 { image.width * 2 + scrollingSpeed, 10 }, 0.0f, 2.0f, WHITE);
}
