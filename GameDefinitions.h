#pragma once
char const Spritesheet_Path[] = ".\\resources\\snake.png";
char const Resources_map[] = ".\\resources\\input.txt";
char const Font_Path[] = ".\\resources\\rfont.ttf";

int const WIDTH_TILES_MAX = 40;
int const HEIGHT_TILES_MAX = 24;

//can not be less than 2
int const SNAKE_INIT_SIZE = 3;

//DO NOT CHANGE IT!!
int const PIXIL_L = 8;

int const TILE_L = 3;
int const TILE_SIZE = PIXIL_L * TILE_L;

int const GAME_W_MAX = WIDTH_TILES_MAX * TILE_SIZE;
int const GAME_H_MAX = HEIGHT_TILES_MAX * TILE_SIZE;

int const SCORE_H = 3;
int const GAMEwin_W_MAX = WIDTH_TILES_MAX * TILE_SIZE;
int const GAMEwin_H_MAX = (HEIGHT_TILES_MAX + 0)* TILE_SIZE;

int const GAME_SPEED = 7; //FPS
int const COLLECTIBLES_N = 4;
int const MOVING_OBSTACLES_N = 2;