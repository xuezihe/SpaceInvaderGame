#pragma once
#include "raylib.h"


//define
#define NUM_SHOOTS 10
#define NUM_MAX_ENEMIES 80
#define FIRST_WAVE 10
#define SECOND_WAVE 20
#define THIRD_WAVE 80
static const int screenWidth = 800;
static const int screenHeight = 450;
static const int fps = 60;
#define PLAYER_SHIP_WIDTH     30
#define PLAYER_SHIP_HEIGHT     30
#define ENEMYSHIP_WIDTH        15
#define ENEMYSHIP_HEIGHT        15

// structure define
typedef enum { FIRST, SECOND, THIRD } EnemyWave;

typedef struct Player {
    Rectangle rec;
    Vector2 speed;
    Color color;
} Player;

typedef struct Enemy {
    Rectangle rec;
    Vector2 speed;
    bool active;
    Color color;
} Enemy;

typedef struct Shoot {
    Rectangle rec;
    Vector2 speed;
    bool active;
    Color color;
} Shoot;
