#pragma once

#include "Obstacle.h"

class MovingObstacle: public Obstacle
{
public:
	void setSpeed(float s);
	float getLinSpeed();
	float getRotSpeed();

	MovingObstacle(sf::Sprite* sprite, Assets type);

protected:
	float linSpeed;
	float rotSpeed;
	float const LIN_TO_ROT = 0.1;
};

