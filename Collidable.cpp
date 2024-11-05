#include "Collidable.h"
bool Collidable::checkCollisionWithWindow()
{

	return false;
}
bool Collidable::checkCollisionWithWall()
{
	return false;
}
sf::Sprite* Collidable::checkCollisionWithCollidable()
{
	return NULL;
}
void Collidable::onCollision()
{
	//Map::map[(int)position.x][(int)position.y] = NULL;
}

Collidable* Collidable::checkCollision()
{
	return NULL;
}