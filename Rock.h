#pragma once
#include "MovingObstacle.h"

class Rock: public  MovingObstacle
{
	Rock();
	void onCollision();
};

