#include "Game.h"

#include <cassert>
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
void Game::tick()
{
	BeginDrawing();
	update();
	draw();
	EndDrawing();
}

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
