#include "Generator.h"

Collectible* AllCollectables[COLLECTIBLES_N];
MovingObstacle* AllMovingObs[MOVING_OBSTACLES_N];
bool static called = false;

Generator::Generator(sf::Time interv)
{
	coolDowmInterval = interv;
	if (!called)
	{
		called = true;
		updateAllCollectables();
		updateAllMovingObs();
	}
}
Generator::~Generator()
{
}
void Generator::updateAllCollectables()
{
	AllCollectables[0] = new Collectible(&redApple, Assets::RedApple);
	AllCollectables[1] = new Collectible(&greenApple, Assets::GreenApple);
	AllCollectables[2] = new Collectible(&goldenApple, Assets::GoldenApple);
	AllCollectables[3] = new Collectible(&cherry, Assets::Cherry);
}
void Generator::updateAllMovingObs()
{
	AllMovingObs[0] = new MovingObstacle(&rock, Assets::Rock);
	AllMovingObs[1] = new MovingObstacle(&shuriken, Assets::Shuriken);
}

Collidable* Generator::generate(Assets assest,int i, int j)
{
	if(clock.getElapsedTime() > coolDowmInterval)
	{
		Collidable* guard = findAssest(assest);
		if (guard)
		{
			Assest temp = guard->assest;
			temp.sprite->setPosition(j * TILE_SIZE + TILE_SIZE / 2, i * TILE_SIZE + TILE_SIZE / 2);
			world[i][j] = new Assest(temp.sprite, temp.type);
			clock.restart();
			generated = true;
		}
		return guard;
	}
	return NULL;
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