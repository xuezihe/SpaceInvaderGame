#include "background.h"




void background::init()
{
	scrollingSpeed = 0.0f;
	image = LoadTexture("game/src/rscs/space.png");
}


void background::updateBackground()
{
	scrollingSpeed -= 0.5f;
	if (scrollingSpeed <=-image.width*2)
	{
		scrollingSpeed = 0;
	}
}

void background::drawBackground()
{
	DrawTextureEx(image, Vector2 { scrollingSpeed, 20 }, 0.0f, 2.0f, WHITE);
	DrawTextureEx(image, Vector2 { image.width * 2 + scrollingSpeed, 20 }, 0.0f, 2.0f, WHITE);
}
