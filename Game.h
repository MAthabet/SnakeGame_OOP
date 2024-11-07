#pragma once
#include "Includes.h"

class Game
{
public :
	sf::Clock clock;
	sf::Time gameTime;
	bool IsRunning;

	Game();
	void run();

private:
	float const APPLE_COOLDOWN_TIME = GAME_SPEED;
	float const GOLDEN_APPLE_TIME = GAME_SPEED;
	float const CHERRY_COOLDOWN_TIME = GAME_SPEED/0.7;
	float const CHERRY_TIME = GAME_SPEED/1.25;

	float const ROCK_COOLDOWN_TIME = GAME_SPEED*1.5;
	float const SHURIKEN_COOLDOWN_TIME = GAME_SPEED;

	sf::RenderWindow window;

	Snake player;
	Map map;

	void start();
	void loop();
	void end();
	void restart();

	void openGameWin();
	int loadSpritesheet();
	void updateAllMovingObs();
	void updateAllCollectables();

	void handleDeath();
	void handleinput();
	void invertInput();
	void moveAllObs(float speed);
	void flipAllcol(float speed = 1);


	Collidable* generateFood(Generator* generator);
	Collidable* generateApple(Generator* generator);
	Collidable* forceGenerateApple(Generator* generator);
	Collidable* generateGoldenApple(Generator* generator);
	Collidable* generateCherry(Generator* generator);

	Collidable* generateMovingObs(Generator* generator);
	Collidable* generateRock(Generator* generator);
	Collidable* generateShuriken(Generator* generator);

};

