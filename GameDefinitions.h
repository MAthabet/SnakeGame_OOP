#pragma once

char const Spritesheet_Path[] = ".\\resources\\snake.png";

int const WIDTH_TILES_MAX = 40;
int const HEIGHT_TILES_MAX = 24;

int const SNAKE_INIT_SIZE = 10;

int const PIXIL_L = 8;
int const TILE_L = 3;
int const TILE_SIZE = PIXIL_L * TILE_L;

int const GAME_W_MAX = WIDTH_TILES_MAX * TILE_SIZE;
int const GAME_H_MAX = HEIGHT_TILES_MAX * TILE_SIZE;

float const GAME_SPEED = 5.0f;