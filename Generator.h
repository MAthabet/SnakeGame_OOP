#pragma once
#include <SFML/Graphics.hpp>
#include "Collectible.h"
#include "MovingObstacle.h"
#include "Map.h"
#include "Assets.h"

extern Collectible* AllCollectables[COLLECTIBLES_N];
extern MovingObstacle* AllMovingObs[MOVING_OBSTACLES_N];

class Generator
{
public:
	bool generated = false;
	Generator(sf::Time interv);
	~Generator();
	Collidable* generate(Assets assest, int i, int j);
private:
	void updateAllCollectables();
	void updateAllMovingObs();
	sf::Clock clock;
	sf::Time coolDowmInterval;
	Collidable* findAssest(Assets assest);
};

