#include "Generator.h"

Generator::Generator(sf::Time interv, Map* world)
{
	coolDowmInterval = interv;
	this->map = world;
}

Collidable* Generator::generate(Assets assest,int i, int j)
{
	if(clock.getElapsedTime() > coolDowmInterval)
	{
		forceGenerate(assest, i, j);
	}
	return NULL;
}
Collidable* Generator::forceGenerate(Assets assest, int i, int j)
{
	if (hadGenerated)
	{
		deleteLastGenerated();
		hadGenerated = false;
	}
	Collidable* guard = findAssest(assest);
	if (guard)
	{
		Assest temp = guard->assest;
		temp.sprite->setPosition(j * TILE_SIZE + TILE_SIZE / 2, i * TILE_SIZE + TILE_SIZE / 2);
		world[i][j] = new Assest(temp.sprite, temp.type);
		lastGeneratedIndex = { i,j };
		clock.restart();
		tileNotFree(i, j);
		hadGenerated = true;
	}
	return guard;
}

Collidable* Generator::findAssest(Assets assest)
{
	for (int i = 0; i < COLLECTIBLES_N; i++)
	{
		if (AllCollectables[i]->assest.type == assest)
			return AllCollectables[i];
	}
	for (int i = 0; i < MOVING_OBSTACLES_N; i++)
	{
		if (AllMovingObs[i]->assest.type == assest)
			return AllMovingObs[i];
	}
	return NULL;
}

std::pair<int, int> Generator::generateEmptyTile()
{
	int x = map->emptyTiles.size();
	if (x<1) 
	{
		return { -1,-1 };
	}
	srand(time(0));
	int indx = rand() % map->emptyTiles.size();

	std::pair<int, int> genrated = map->emptyTiles[indx];

	return genrated;
}

void Generator::tileNotFree(int indx)
{
	map->emptyTiles[indx] = map->emptyTiles.back();

	map->emptyTiles.pop_back();
}

void Generator::tileNotFree(int i, int j)
{
	auto it = std::remove_if(map->emptyTiles.begin(), map->emptyTiles.end(),
		[i, j](const std::pair<int, int>& p) {
			return p.first == i && p.second == j;
		});
	if (it != map->emptyTiles.end())
	{
		map->emptyTiles.erase(it, map->emptyTiles.end());
	}
}
void Generator::DeleteTile(int i, int j)
{
	if (world[i][j])
	{
		world[i][j] = NULL;
	}
	map->tileIsEmpty({ i,j });
}
void Generator::deleteLastGenerated()
{
	DeleteTile(lastGeneratedIndex.first, lastGeneratedIndex.second);
}
bool Generator::hasGenerated()
{
	return hadGenerated;
}
