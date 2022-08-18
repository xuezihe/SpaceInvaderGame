#include "Game.h"

#include <cassert>
Game::Game(int width, int height, int fps, std::string title):_board(width, height)
{
	assert(!IsWindowReady());
	InitWindow(width, height, title.c_str());
	SetTargetFPS(fps);
	_board.initGame();
	_board.loadImage();

}
Game::~Game()
{
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
	_board.boardLogic();
}


// game drawing per frame
void Game::draw()
{
	_board.boarddraw();
}
