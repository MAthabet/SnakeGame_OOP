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
	sf::RenderWindow window;

	Snake player;
	Map map;

	Generator obstaclesGenerator{ sf::seconds(50 / GAME_SPEED), &map };
	Generator collecablesGenerator{ sf::seconds(21 / GAME_SPEED), &map };

	void start();
	void loop();
	void end();
	void restart();
	void generateCollictable(Generator* collectableGen);
	void generateMovingObs();
	void openGameWin();
	int loadSpritesheet();
	void updateAllMovingObs();
	void updateAllCollectables();
	void handleDeath();
	void handleinput();
	void invertInput();
	void generateApple();
	void generateGoldenApple();
	void generateCherry();
	void generateRock();
	void generateShuriken();

};

