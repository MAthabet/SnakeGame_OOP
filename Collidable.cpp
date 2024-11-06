#include "Collidable.h"
#include "Assets.h"

Collidable::Collidable()
{
	this->assest.sprite = NULL;
	this->assest.type = None;
}
Collidable::Collidable(sf::Sprite* sprite, Assets type)
{
	this->assest.sprite = sprite;
	this->assest.type = type;
}
bool Collidable::checkCollision()
{
	bool isColided = false;
	if (checkCollisionWithWindow())
	{
		handleCollisionWithWindow();
		Assest* colidedWith = NULL;
		return true;
	}
	int j = position.x / TILE_SIZE;
	int i = position.y / TILE_SIZE;
	Assets current;
	if (world[i][j])
	{
		current = world[i][j]->type;
		this->colidedWith = world[i][j];
		switch (current)
		{
		case Wall:
			handleCollisionWithWall();
			isColided = true;
			break;
		case RedObstacle:
		case BlueObstacle:
			handleCollisionWithStationryObstacle();
			isColided = true;
			break;
		case Rock:
		case Shuriken:
			handleCollisionWithMovingObstacle();
			isColided = true;
			break;
		case RedApple:
		case GreenApple:
		case GoldenApple:
		case Cherry:
			handleCollisionWithCollectable();
			isColided = true;
			break;
		default:
			break;
		}
	}
	return isColided;
}
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
void Collidable::handleCollisionWithWindow()
{
	DeleteTile(position.x / TILE_SIZE, position.y / TILE_SIZE);
	delete this;
}
void Collidable::handleCollisionWithWall()
{
	DeleteTile(this->position.x / TILE_SIZE, this->position.y / TILE_SIZE);
	delete this;
}

void Collidable::handleCollisionWithCollectable()
{
	DeleteTile(colidedWith->sprite->getPosition().x / TILE_SIZE, colidedWith->sprite->getPosition().y / TILE_SIZE);
}
void Collidable::handleCollisionWithMovingObstacle()
{
	DeleteTile(colidedWith->sprite->getPosition().x / TILE_SIZE, colidedWith->sprite->getPosition().y / TILE_SIZE);
}
void Collidable::handleCollisionWithStationryObstacle()
{
	DeleteTile(position.x / TILE_SIZE, position.y / TILE_SIZE);
	delete this;
}

void Collidable::DeleteTile(int j, int i)
{
	world[i][j]->sprite = NULL;
	world[i][j]->type = None;
}

void Collidable::updatePosition()
{
	this->position.x = assest.sprite->getPosition().x;
	this->position.y = assest.sprite->getPosition().y;
}