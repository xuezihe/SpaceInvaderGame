#pragma once
#include <string>
#include "board.h"
#include "background.h"



class Game
{
public:
	Game(int width, int height, int fps, std::string title);
	~Game();
	Game(const Game& other) = delete;
	void tick();
	bool gameShouldClose() const;
	game::board getboard() { return _board; };
private:
	void update();
	void draw();
	game::board _board;
	background _backGround;


};
