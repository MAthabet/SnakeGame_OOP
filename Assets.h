#pragma once
#include <SFML/Graphics.hpp>

enum Assets
{
    None, RedApple, Head, GreenApple, Body, Wall, RedObstacle, BlueObstacle, Rock,
    Shuriken, GoldenApple, Window, Cherry = 15
};

struct Assest
{
	sf::Sprite* sprite;
	Assets type;
	Assest() : sprite(NULL), type(None) {};
	Assest(sf::Sprite* s, Assets t) : sprite(s), type(t){}
	void flip(float speed = 1);
	void rotate(float speed);
private:
	bool inv = false;
	void flipInv(float speed);
};

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



