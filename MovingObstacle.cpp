#include "MovingObstacle.h"

MovingObstacle::MovingObstacle(sf::Sprite* sprite, Assets type)
{
	this->assest.sprite = sprite;
	this->assest.type = type;
	direction = {1,0};
}
MovingObstacle::MovingObstacle(sf::Sprite* sprite, Assets type, Axis axis)
{
	this->assest.sprite = sprite;
	this->assest.type = type;
	this->axis = axis;
	if(axis == Horizontal) direction = { 1,0 };
	else direction = { 0,1 };
}

void MovingObstacle::move(float speed)
{
	setSpeed(speed);
	int Oldx = assest.sprite->getPosition().x;
	int Oldy = assest.sprite->getPosition().y;
	int Newx = Oldx + direction.x * TILE_SIZE * linSpeed;
	int Newy = Oldy + direction.y * TILE_SIZE * linSpeed;

	assest.sprite->setPosition(Newx,Newy);
	assest.rotate(rotSpeed);

	DeleteTile(Oldy, Oldx);
}


void MovingObstacle::setSpeed(float s)
{
	linSpeed = s;
	rotSpeed = linSpeed * LIN_TO_ROT;
}
float MovingObstacle::getLinSpeed()
{
	return linSpeed;
}
float MovingObstacle::getRotSpeed()
{
	return rotSpeed;
}
