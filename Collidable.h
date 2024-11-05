#pragma once
#include <SFML/Graphics.hpp>
#include "Map.h"



class Collidable
{
public:
	sf::Sprite sprite;
	sf::Vector2f position;
	virtual void updatePosition() = 0;
	virtual void onCollision(Map* map);
	virtual Collidable* checkCollision();

protected:
	bool checkCollisionWithWindow();
	bool checkCollisionWithWall(Map* world);
	bool checkCollisionWithCollectable(Map* world);
	bool checkCollisionWithMovingObstacle(Map* world);
	bool checkCollisionWithStationryObstacle(Map* world);
};

