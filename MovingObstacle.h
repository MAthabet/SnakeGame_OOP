#pragma once

#include "Obstacle.h"

class MovingObstacle: public Obstacle
{
public:
	void setSpeed(float s);
	float getLinSpeed();
	float getRotSpeed();

protected:
	float linSpeed;
	float rotSpeed;
	float const LIN_TO_ROT = 0.1;
	virtual void onCollision() = 0;
};

