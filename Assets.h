#pragma once
#include <SFML/Graphics.hpp>
extern std::string const Spritesheet_Path;

int const PIXIL_L = 8;
int const TILE_L = 3;
int const TILE_SIZE = PIXIL_L * TILE_L;

/*
extern sf::IntRect headRect;
extern sf::IntRect headUpRect;
extern sf::IntRect headDownRect;
extern sf::IntRect headLeftRect;
extern sf::IntRect bodyRect;

extern sf::IntRect wallUPRect;
extern sf::IntRect wallLeftRect;
extern sf::IntRect wallRightRect;
extern sf::IntRect wallDownRect;

extern sf::IntRect redObstacleRect;
extern sf::IntRect blueObstacleRect;
extern sf::IntRect rockRect;
extern sf::IntRect shurikenRect;
 
extern sf::IntRect redAppleRect;
extern sf::IntRect greenAppleRect;
extern sf::IntRect goldenAppleRect;
extern sf::IntRect cherryRect;
*/

extern sf::Texture spritesheet;

extern sf::Sprite head;
extern sf::Sprite headUp;
extern sf::Sprite headDown;
extern sf::Sprite headLeft;
extern sf::Sprite body;

extern sf::Sprite wallUp;
extern sf::Sprite wallLeft;
extern sf::Sprite wallRight;
extern sf::Sprite wallDown;
extern sf::Sprite redObstacle;
extern sf::Sprite blueObstacle;
extern sf::Sprite wall;

extern sf::Sprite rock;
extern sf::Sprite shuriken;
extern sf::Sprite redApple;
extern sf::Sprite greenApple;
extern sf::Sprite goldenApple;
extern sf::Sprite cherry;


void resizeAllAssets();



