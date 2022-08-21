#include <cassert>
#include "Game.h"

// wrap the game window
Game::Game(int width, int height, int fps, std::string title) :_board(width, height)
{
	assert(!IsWindowReady());
	InitWindow(width, height, title.c_str());
	SetTargetFPS(fps);
	_board.initGame();
	_board.loadImage();
	_backGround.init();

}
Game::~Game()
{
	UnloadTexture(_backGround.image);
	CloseWindow();
}
// executed per frame, integrate update() and draw() 
void Game::tick()
{
	BeginDrawing();
	update();
	draw();
	EndDrawing();
}

// wrap the check window close function 
bool Game::gameShouldClose() const
{
	return WindowShouldClose();

}

// game mechanic per frame
void Game::update()
{
	_backGround.updateBackground();
	_board.boardLogic();

}


// game drawing per frame
void Game::draw()
{
	_backGround.drawBackground();
	_board.boarddraw();

}
