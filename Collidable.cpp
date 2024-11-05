#include "Collidable.h"
bool Collidable::checkCollisionWithWindow()
{
	int x = position.x;
	int y = position.y;
	if ( x >= GAME_W_MAX || x <= 0 )
		return true;
	if (y >= GAME_H_MAX || y <= 0)
		return true;
	return false;
}
bool Collidable::checkCollisionWithWall(Map* world)
{
	int j = position.x/ TILE_SIZE;
	int i = position.y/ TILE_SIZE;
	if(world->map[i][j])
	if (world->map[i][j]->type == Wall)
	{
		return true;
	}
	return false;
}

bool Collidable::checkCollisionWithCollectable(Map* world)
{
	return false;
}
bool Collidable::checkCollisionWithMovingObstacle(Map* world)
{
	return false;
}
bool Collidable::checkCollisionWithStationryObstacle(Map* world)
{
	return false;
}
void Collidable::onCollision(Map* game)
{
	if (checkCollision() == NULL) return;

	game->map[(int)position.x][(int)position.y] = NULL;
}

Collidable* Collidable::checkCollision()
{
	return NULL;
}