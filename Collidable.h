#pragma once
#include <SFML/Graphics.hpp>
#include "Map.h"

class Collidable
{
public:
	Assest assest;
	sf::Vector2f position;
	virtual void updatePosition();
	bool checkCollision();
	Collidable();
	Collidable(sf::Sprite* sprite, Assets type);
protected:
	Assest* colidedWith = NULL;
	bool checkCollisionWithWindow();
	virtual void handleCollisionWithWindow();
	virtual void handleCollisionWithWall();
	virtual void handleCollisionWithCollectable();
	virtual void handleCollisionWithMovingObstacle();
	virtual void handleCollisionWithStationryObstacle();
	void DeleteTile(int i, int j);
};

