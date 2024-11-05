#pragma once
#include <SFML/Graphics.hpp>
//#include "Map.h"

enum collidables
{
	Head, Body, Wall, RedObstacle, BlueObstacle, Rock, Shuriken, RedApple, GreenApple, GoldenApple, Cherry
};

class Collidable
{
public:
	collidables type;
	//sf::Sprite sprite;
	sf::Vector2f position;
	virtual void updatePosition() = 0;
	virtual void onCollision();
	virtual Collidable* checkCollision();

protected:
	bool checkCollisionWithWindow();
	bool checkCollisionWithWall();
	sf::Sprite* checkCollisionWithCollidable();
};

