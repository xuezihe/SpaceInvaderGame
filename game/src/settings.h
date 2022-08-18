#pragma once
#include "raylib.h"


//define
#define NUM_SHOOTS 50
#define NUM_MAX_ENEMIES 50
#define FIRST_WAVE 10
#define SECOND_WAVE 20
#define THIRD_WAVE 50
static const int screenWidth = 800;
static const int screenHeight = 450;
static const int fps = 60;

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
