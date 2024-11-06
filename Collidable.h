#pragma once
#include <SFML/Graphics.hpp>
#include "Map.h"

class Collidable
{
public:
	Map* map;
	Assest assest;
	sf::Vector2f position;
	Assest* colidedWith = NULL;
	virtual void updatePosition();
	virtual bool checkCollision();
	Collidable();
	Collidable(sf::Sprite* sprite, Assets type, Map* map);

protected:
	bool checkCollisionWithWindow();
	virtual void handleCollisionWithWindow();
	virtual void handleCollisionWithWall();
	virtual void handleCollisionWithCollectable();
	virtual void handleCollisionWithMovingObstacle();
	virtual void handleCollisionWithStationryObstacle();
	void DeleteTile(int i, int j);
};

