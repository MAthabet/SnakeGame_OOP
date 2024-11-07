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
	Generator(Map* world) : map(world) {};
	Collidable* generate(Assets assest, int i, int j);
	Collidable* forceGenerate(Assets assest, int i, int j);

	std::pair<int, int> generateEmptyTile();
	void deleteLastGenerated();
	bool hasGenerated();

private:
	std::pair<int, int> lastGeneratedIndex;
	bool hadGenerated = false;
	Map* map;
	sf::Clock clock;
	sf::Time coolDowmInterval;
	Collidable* findAssest(Assets assest);
	void tileNotFree(int indx);
	void tileNotFree(int i, int j);
	void DeleteTile(int j, int i);

};

