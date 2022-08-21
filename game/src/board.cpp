#include "cassert"
#include "board.h"



game::board::board(int screenWidth, int screenHeight):_screenWidth(screenWidth),_screenHeight(screenHeight){}

game::board::~board()
{
	UnloadTexture(_playership);
	UnloadTexture(_enemyTexture);
}

void game::board::initGame()
{
    shootRate = 0;
    pause = false;
    gameOver = false;
    victory = false;
    smooth = false;
    wave = FIRST;
    activeEnemies = FIRST_WAVE;
    enemiesKill = 0;
    score = 0;
    alpha = 0;

    // Initialize player
    player.rec.x = 20;
    player.rec.y = 50;
    player.rec.width = PLAYER_SHIP_WIDTH;
    player.rec.height = PLAYER_SHIP_HEIGHT;
    player.speed.x = 5;
    player.speed.y = 5;
    player.color = BLACK;
	_ammo = AMMO_NUM;
	_needToReload = false;

    // Initialize enemies
    for (int i = 0; i < NUM_MAX_ENEMIES; i++)
    {
        enemy[i].rec.width = ENEMYSHIP_WIDTH;
        enemy[i].rec.height = ENEMYSHIP_HEIGHT;
        enemy[i].rec.x = GetRandomValue(_screenWidth, _screenWidth + 1000);
        enemy[i].rec.y = GetRandomValue(0, _screenHeight - enemy[i].rec.height);
        enemy[i].speed.x = 5;
        enemy[i].speed.y = 5;
        enemy[i].active = true;
        enemy[i].color = GRAY;
    }

    // Initialize shoots
    for (int i = 0; i < NUM_SHOOTS; i++)
    {
        shoot[i].rec.x = player.rec.x;
        shoot[i].rec.y = player.rec.y + player.rec.height / 4;
        shoot[i].rec.width = 10;
        shoot[i].rec.height = 5;
        shoot[i].speed.x = 7;
        shoot[i].speed.y = 0;
        shoot[i].active = false;
        shoot[i].color = MAROON;
    }
	DrawText("START FIGHT!", _screenWidth / 2 - MeasureText("START FIGHT!", 40) / 2, _screenHeight / 2 - 40, 40, Fade(BLACK, alpha));
}



void game::board::boardLogic()
{
	if (!gameOver)
	{
		if (IsKeyPressed(KEY_P))
		{
            pause = !pause;
		}
		if (!pause)
		{
			switch (wave)
			{
			case FIRST:
				{
					if (!smooth)
					{
	                    alpha += 0.02f;
	                    if (alpha >=1.0f)
	                    {
	                        smooth = true;
	                    }
					}
					if (smooth)
					{
	                    alpha -= 0.2f;
					}
	                if (enemiesKill == activeEnemies)
	                {
	                    enemiesKill = 0;

	                    for (int i = 0; i < activeEnemies; i++)
	                    {
	                        if (!enemy[i].active) enemy[i].active = true;
	                    }

	                    activeEnemies = SECOND_WAVE;
	                    wave = SECOND;
	                    smooth = false;
	                    alpha = 0.0f;
	                }
				}
			case SECOND:
				{
	                if (!smooth)
	                {
	                    alpha += 0.02f;

	                    if (alpha >= 1.0f) smooth = true;
	                }

					if (smooth) 
					{
						alpha -= 0.02f;
					}


	                if (enemiesKill == activeEnemies)
	                {
	                    enemiesKill = 0;

	                    for (int i = 0; i < activeEnemies; i++)
	                    {
							if (!enemy[i].active)
							{
								enemy[i].active = true;
							}
	                    }

	                    activeEnemies = THIRD_WAVE;
	                    wave = THIRD;
	                    smooth = false;
	                    alpha = 0.0f;
	                }
				}
			case THIRD:
				{
					if (!smooth)
					{
						alpha += 0.02f;

						if (alpha >= 1.0f)
						{
							smooth = true;
						}
					}

					if (smooth) alpha -= 0.02f;

					if (enemiesKill == activeEnemies)
					{
						victory = true;
					}

				}
			}

			// player movement
			if (IsKeyDown(KEY_D))
			{
				player.rec.x += player.speed.x;
			}
			if (IsKeyDown(KEY_A))
			{
				player.rec.x -= player.speed.x;
			}
			if (IsKeyDown(KEY_W))
			{
				player.rec.y -= player.speed.y;
			}
			if (IsKeyDown(KEY_S))
			{
				player.rec.y += player.speed.y;
			}

			// player reload
			if (IsKeyPressed(KEY_R))
			{
				reload();
			}

			// Player collision with enemy
			for (int i = 0; i < activeEnemies; i++)
			{
				if (CheckCollisionRecs(player.rec, enemy[i].rec)) gameOver = true;
			}

			// Enemy behaviour
			for (int i = 0; i < activeEnemies; i++)
			{
				if (enemy[i].active)
				{
					enemy[i].rec.x -= enemy[i].speed.x;

					if (enemy[i].rec.x < 0)
					{
						enemy[i].rec.x = GetRandomValue(_screenWidth, _screenWidth + 1000);
						enemy[i].rec.y = GetRandomValue(0, _screenHeight - enemy[i].rec.height);
					}
				}
			}
			// Wall behaviour
			if (player.rec.x <= 0)
			{
				player.rec.x = 0;
			}
			if (player.rec.x + player.rec.width >= _screenWidth)
			{
				player.rec.x = _screenWidth - player.rec.width;
			}
			if (player.rec.y <= 0) {player.rec.y = 0;}
			if (player.rec.y + player.rec.height >= _screenHeight) {player.rec.y = _screenHeight - player.rec.height;}

			// Shoot initialization
			if (IsKeyDown(KEY_SPACE))
			{
				shootRate += 4;

				for (int i = 0; i < NUM_SHOOTS; i++)
				{
					if (!shoot[i].active && shootRate % 20 == 0 && _ammo>0)
					{
						shoot[i].rec.x = player.rec.x;
						shoot[i].rec.y = player.rec.y + player.rec.height / 4;
						shoot[i].active = true;
						_ammo--;
						break;
					}
					if (_ammo<=0)
					{
						_needToReload = true;
					}
				}
			}

			// Shoot logic
			for (int i = 0; i < NUM_SHOOTS; i++)
			{
				if (shoot[i].active)
				{
					// Movement
					shoot[i].rec.x += shoot[i].speed.x;

					// Collision with enemy
					for (int j = 0; j < activeEnemies; j++)
					{
						if (enemy[j].active)
						{
							if (CheckCollisionRecs(shoot[i].rec, enemy[j].rec))
							{
								shoot[i].active = false;
								enemy[j].rec.x = GetRandomValue(_screenWidth, _screenWidth + 1000);
								enemy[j].rec.y = GetRandomValue(0, _screenHeight - enemy[j].rec.height);
								shootRate = 0;
								enemiesKill++;
								score += 100;
							}

							if (shoot[i].rec.x + shoot[i].rec.width >= _screenWidth)
							{
								shoot[i].active = false;
								shootRate = 0;
							}
						}
					}
				}
			}

		}
	}
	else
	{
	if (IsKeyPressed(KEY_ENTER))
		{
			initGame();
			gameOver = false;
		}
	}
}

void game::board::boarddraw()
{
	ClearBackground(RAYWHITE);
	if (!gameOver)
	{
		// draw player
		DrawTexture(_playership, player.rec.x -5, player.rec.y-20, WHITE);

		// draw wave
		if (wave == FIRST)
		{
			DrawText("FIRST WAVE", _screenWidth / 2 - MeasureText("FIRST WAVE", 40) / 2, _screenHeight / 2 - 40, 40, Fade(BLACK, alpha));
		}
		else if (wave ==SECOND)
		{
			DrawText("SECOND WAVE", _screenWidth / 2 - MeasureText("SECOND WAVE", 40) / 2, _screenHeight / 2 - 40, 40, Fade(BLACK, alpha));
		}
		else
		{
			DrawText("FINAL WAVE", _screenWidth / 2 - MeasureText("THIRD WAVE", 40) / 2, _screenHeight / 2 - 40, 40, Fade(BLACK, alpha));
		}
		for (int i = 0; i < activeEnemies; i++)
		{
			if (enemy[i].active)
			{
				DrawTexture(_enemyTexture, enemy[i].rec.x , enemy[i].rec.y , WHITE);
			}
		}
		// draw shoot
		for (int i = 0; i < NUM_SHOOTS; i++)
		{
			if (shoot[i].active) {DrawRectangleRec(shoot[i].rec, shoot[i].color);}
		}

		// draw scroe
		DrawText(TextFormat("%04i", score), 20, 20, 40, GRAY);
		DrawText(TextFormat("AMMO: %04i", _ammo), screenWidth-250, 20, 40, GRAY);

		if (victory)
		{
			DrawText("YOU WIN", _screenWidth / 2 - MeasureText("YOU WIN", 40) / 2, _screenHeight / 2 - 40, 40, GOLD);
		}

		if (pause)
		{
			DrawText("GAME PAUSED", _screenWidth / 2 - MeasureText("GAME PAUSED", 40) / 2, _screenHeight / 2 - 40, 40, RAYWHITE);
		}
	}
	else
	{
		DrawText("PRESS [ENTER] TO PLAY AGAIN", _screenWidth / 2 - MeasureText("PRESS [ENTER] TO PLAY AGAIN", 20) / 2, _screenHeight / 2 - 50, 20, RAYWHITE);
	}

}

void game::board::loadImage()
{
	Image playerimage = LoadImage("game/src/src/Ship.png");
	assert(playerimage.width>=64);
	_playership = LoadTextureFromImage(playerimage);
	Image enemyImage = LoadImage("game/src/src/enemy.png");
	ImageResize(&enemyImage, ENEMYSHIP_WIDTH, ENEMYSHIP_HEIGHT);
	_enemyTexture = LoadTextureFromImage(enemyImage);

	UnloadImage(playerimage);
}

void game::board::reload()
{
	_ammo = AMMO_NUM;
}


