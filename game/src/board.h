#include "settings.h"


namespace game
{

	class board
	{
	public:
		board(int screenWidth, int screenHeight);
		void initGame();
        void boardLogic();
		void boarddraw();


	public:
		Player player = { 0 };
		Enemy enemy[NUM_MAX_ENEMIES] = { 0 };
		Shoot shoot[NUM_SHOOTS] = { 0 };
		EnemyWave wave = { EnemyWave(0) };
		int shootRate = 0;
		float alpha = 0.0f;
		int activeEnemies = 0;
		int enemiesKill = 0;
		bool smooth = false;

		bool pause, gameOver, victory;
		int score;
		int  _screenWidth;
		int _screenHeight;



	};

	
}
