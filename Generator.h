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
	Generator(sf::Time interv, Map* world);
	Collidable* generate(Assets assest, int i, int j);
	std::pair<int, int> generateEmptyTile();
	bool hadGenerated = false;
private:
	std::pair<int, int> lastGeneratedIndex;
	Map* map;
	sf::Clock clock;
	sf::Time coolDowmInterval;
	Collidable* findAssest(Assets assest);
	void tileNotFree(int indx);
	void tileNotFree(int i, int j);
	void DeleteTile(int j, int i);

};

