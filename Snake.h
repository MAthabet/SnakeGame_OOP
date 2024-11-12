#pragma once

#include <SFML/Graphics.hpp>

#include "GameDefinitions.h"
#include "Assets.h"
#include "Collidable.h"

enum class Direction { Up, Down, Left, Right };

class Snake: public Collidable
{
public:
	bool golden;
	Direction lastInput = Direction::Right;
	std::vector<sf::Sprite> snake;
	int health = 2;
	bool shielded = false;
	bool invertedInput = false;
	bool collidedWithWin = false;
	bool haseEatenApple = true;
	int collectedApples = 0;
	void draw(sf::RenderWindow* win);
	int Score = 0;

	Snake();

	bool checkCollision();
	void initSnake(int snakeLength, sf::Vector2f start, Map* map);
	void move();
	void setStartPosition(sf::Vector2f startPosition);
	void increaseHealth(int toIncrease);
	bool isAlive();
	void setSpeed(int speed);
	void updatePosition();
	void checkSelfCollision();
	void handleCollisionWithMovingObstacle(Assest* assest, int collidedHere);
	bool Alive = true;

private:
	int speed;
	void handleDeath();
	void handleCollisionWithWindow();
	void handleCollisionWithCollectable();
	void handleCollisionWithStationryObstacle();
	void handleCollisionWithWall();
	void updateDirection();
	void grow();
	void shrink();
	void cut(int collidedHere);
	sf::Vector2i direction;
	sf::Vector2f tailStartPosition;
};